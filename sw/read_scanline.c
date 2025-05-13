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

#define DEVICE_PATH "/dev/camera"
#define POLL_DELAY_US 1000  // 1 ms between polls
#define PIXEL_COUNT 640     // Number of 16-bit RGB565 pixels to collect

// Convert RGB565 to 8-bit grayscale
uint8_t rgb565_to_gray(uint16_t pixel) {
    uint8_t r = (pixel >> 11) & 0x1F;
    uint8_t g = (pixel >> 5)  & 0x3F;
    uint8_t b = pixel & 0x1F;

    r = (r << 3) | (r >> 2);  // scale to 8-bit
    g = (g << 2) | (g >> 4);
    b = (b << 3) | (b >> 2);

    return (77 * r + 150 * g + 29 * b) >> 8;  // weighted grayscale
}

int main() {
    int fd, count = 0;
    uint16_t pixels[PIXEL_COUNT];
    uint8_t grayscale[PIXEL_COUNT];

    // Open camera device
    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /dev/camera");
        return EXIT_FAILURE;
    }

    // Wait until FIFO is not empty (camera has started sending data)
    printf("Waiting for FIFO to have data...\n");
    int empty = 1;
    do {
        if (ioctl(fd, CAMERA_FIFO_EMPTY, &empty) < 0) {
            perror("ioctl CAMERA_FIFO_EMPTY failed");
            close(fd);
            return EXIT_FAILURE;
        }
        usleep(POLL_DELAY_US);
    } while (empty);

    printf("FIFO has data. Reading scanline...\n");

    // Read until we've collected 640 16-bit pixels
    while (count < PIXEL_COUNT) {
        uint32_t word;
        if (ioctl(fd, CAMERA_READ_WORD, &word) < 0) {
            perror("ioctl CAMERA_READ_WORD failed");
            close(fd);
            return EXIT_FAILURE;
        }

        pixels[count++] = word & 0xFFFF;
        if (count < PIXEL_COUNT)
            pixels[count++] = word >> 16;
    }

    close(fd);

    // Convert to grayscale
    for (int i = 0; i < PIXEL_COUNT; ++i) {
        grayscale[i] = rgb565_to_gray(pixels[i]);
    }

    // Process the grayscale scanline
    process_barcode(grayscale);

    return EXIT_SUCCESS;
}
