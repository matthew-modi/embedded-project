#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include "camera.h"
#include "barcode_decoder.h"

#define DEVICE_PATH   "/dev/camera"
#define POLL_DELAY_US 1000    // 1 ms between polls
#define PIXEL_COUNT   640     // Number of 16-bit RGB565 pixels to collect

// Must match the bit‐field in barcode_decoder.h
typedef struct {
    uint8_t b : 5;
    uint8_t g : 6;
    uint8_t r : 5;
} rgb565_t;

int main(void) {
    int fd, count = 0;
    rgb565_t pixels[PIXEL_COUNT];

    // Open camera device
    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /dev/camera");
        return EXIT_FAILURE;
    }

    // Wait until FIFO has data
    printf("Waiting for FIFO to have data…\n");
    int empty = 1;
    do {
        if (ioctl(fd, CAMERA_FIFO_EMPTY, &empty) < 0) {
            perror("ioctl CAMERA_FIFO_EMPTY failed");
            close(fd);
            return EXIT_FAILURE;
        }
        usleep(POLL_DELAY_US);
    } while (empty);

    printf("FIFO has data. Reading scanline…\n");

    // Read until we've collected 640 RGB565 pixels
    while (count < PIXEL_COUNT) {
        uint32_t word;
        if (ioctl(fd, CAMERA_READ_WORD, &word) < 0) {
            perror("ioctl CAMERA_READ_WORD failed");
            close(fd);
            return EXIT_FAILURE;
        }

        // lower 16 bits
        uint16_t p0 = word & 0xFFFF;
        pixels[count].r = (p0 >> 11) & 0x1F;
        pixels[count].g = (p0 >> 5)  & 0x3F;
        pixels[count].b =  p0        & 0x1F;
        count++;

        // upper 16 bits (if still room)
        if (count < PIXEL_COUNT) {
            uint16_t p1 = word >> 16;
            pixels[count].r = (p1 >> 11) & 0x1F;
            pixels[count].g = (p1 >> 5)  & 0x3F;
            pixels[count].b =  p1        & 0x1F;
            count++;
        }
    }

    close(fd);

    // Process the RGB565 scanline—returns a malloc’d 13-byte string or NULL
    char *upc = process_barcode(pixels, PIXEL_COUNT);
    if (upc) {
        printf("Decoded UPC-A: %s\n", upc);
        free(upc);
    } else {
        printf("Failed to decode barcode\n");
    }

    return EXIT_SUCCESS;
}
