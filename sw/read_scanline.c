#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include "camera.h"

#define DEVICE_PATH "/dev/camera"
#define OUTPUT_FILE "scanline.raw"
#define POLL_DELAY_US 1000  // 1 ms between polls
#define PIXEL_COUNT 640     // Number of 16-bit RGB565 pixels to collect

int main() {
    int fd, count = 0;
    uint16_t pixels[PIXEL_COUNT];
    FILE *outfile;

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

    // Write pixels to file
    outfile = fopen(OUTPUT_FILE, "wb");
    if (!outfile) {
        perror("Failed to open output file");
        return EXIT_FAILURE;
    }

    fwrite(pixels, sizeof(uint16_t), PIXEL_COUNT, outfile);
    fclose(outfile);

    printf("Wrote %d pixels to %s\n", PIXEL_COUNT, OUTPUT_FILE);
    return EXIT_SUCCESS;
}

