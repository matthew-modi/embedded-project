#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_BUS   "/dev/i2c-1"
#define SCCB_ADDR 0x21    // OV7670 7-bit address (0x42>>1)

/// Write one byte to camera register via raw I²C
static int write_reg(int fd, uint8_t reg, uint8_t val) {
    if (ioctl(fd, I2C_SLAVE, SCCB_ADDR) < 0) {
        perror("I2C_SLAVE");
        return -1;
    }
    uint8_t buf[2] = { reg, val };
    if (write(fd, buf, 2) != 2) {
        perror("I2C write");
        return -1;
    }
    return 0;
}

/// Read one byte back (for verification)
static int read_reg(int fd, uint8_t reg, uint8_t *val) {
    if (ioctl(fd, I2C_SLAVE, SCCB_ADDR) < 0) {
        perror("I2C_SLAVE");
        return -1;
    }
    // write register address
    if (write(fd, &reg, 1) != 1) {
        perror("I2C write");
        return -1;
    }
    // read data
    if (read(fd, val, 1) != 1) {
        perror("I2C read");
        return -1;
    }
    return 0;
}

struct regval { uint8_t reg, val; };
static const struct regval ov7670_init[] = {
    {0x12,0x80}, {0x11,0x01}, {0x6B,0x0A}, {0x0C,0x04},
    {0x3E,0x11}, {0x12,0x14}, {0x13,0xE7}, {0x14,0x4A},
    {0x15,0x00}, {0x3D,0x98}, {0x40,0x10}, {0x42,0x08},
    {0x32,0x80}, {0x17,0x11}, {0x18,0x61}, {0x19,0x03},
    {0x1A,0x7B}, {0x03,0x06}, {0x70,0x3A}, {0x71,0x35},
    {0x72,0x11}, {0x73,0x00},
    {0x43,0x14},{0x44,0xF0},{0x45,0x45},{0x46,0x61},
    {0x47,0x51},{0x48,0x79},{0x4B,0x09},{0x4F,0x80},
    {0x50,0x80},{0x51,0x00},{0x52,0x22},{0x53,0x5E},
    {0x54,0x80},{0x58,0x9E},
    {0xFF,0xFF}  // end marker
};

int configure_sccb(void) {
    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) { perror("open"); return -1; }
    for (int i = 0; ov7670_init[i].reg != 0xFF; i++) {
        if (write_reg(fd, ov7670_init[i].reg, ov7670_init[i].val) < 0) {
            close(fd);
            return -1;
        }
        usleep(500);
    }
    uint8_t pid;
    if (read_reg(fd, 0x0A, &pid) == 0)
        printf("PID MSB = 0x%02X\n", pid);
    close(fd);
    return 0;
}

int main(void) {
    if (configure_sccb() < 0) {
        fprintf(stderr, "Failed to configure SCCB\n");
        return 1;
    }
    printf("SCCB configured successfully\n");
    return 0;
}
