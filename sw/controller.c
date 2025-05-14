// sccb_config.c
// Configures DE1-SoC I²C multiplexer (GPIO48) and OV7670 via raw I²C

#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <errno.h>

#define I2C_BUS        "/dev/i2c-1"
#define SCCB_ADDR      0x21        // OV7670 7-bit (0x42>>1)

// Simple write byte via raw I2C
static int write_reg(int fd, uint8_t reg, uint8_t val) {
    if (ioctl(fd, I2C_SLAVE, SCCB_ADDR) < 0) {
        perror("ioctl I2C_SLAVE");
        return -1;
    }
    uint8_t buf[2] = { reg, val };
    if (write(fd, buf, 2) != 2) {
        perror("I2C write");
        return -1;
    }
    return 0;
}

// Simple read byte via raw I2C
static int read_reg(int fd, uint8_t reg, uint8_t *val) {
    if (ioctl(fd, I2C_SLAVE, SCCB_ADDR) < 0) {
        perror("ioctl I2C_SLAVE");
        return -1;
    }
    if (write(fd, &reg, 1) != 1) {
        perror("I2C write reg");
        return -1;
    }
    if (read(fd, val, 1) != 1) {
        perror("I2C read val");
        return -1;
    }
    return 0;
}

struct regval { uint8_t reg, val; };
static const struct regval ov7670_init[] = {
    {0x12, 0x80}, // COM7: reset sensor

    {0x15, 0x00}, // COM10: map HREF→HSYNC for now...
    {0x12, 0x04}, // COM7: select RGB output (no YUV, no Bayer) → our FPGA gets real R/G/B
    {0x40, 0xD0}, // COM15: choose RGB565 output (bits[5:4]=01) and keep full 8-bit range
    
    {0xFF, 0xFF}  // end marker
};


int configure_sccb(void) {
    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) {
        perror("open I2C_BUS");
        return -1;
    }

    for (int i = 0; ov7670_init[i].reg != 0xFF; i++) {
        if (write_reg(fd, ov7670_init[i].reg, ov7670_init[i].val) < 0) {
            fprintf(stderr, "Error! Failed to write reg 0x%02X\n", ov7670_init[i].reg);
            close(fd);
            return -1;
        }

        // skip read-back for the reset
        if (ov7670_init[i].reg == 0x12 && ov7670_init[i].val == 0x80) {
            usleep(50000); // let the sensor finish resetting (50 ms)
            continue;
        }
  
        // Read back to verify
        uint8_t val;
        if (read_reg(fd, ov7670_init[i].reg, &val) == 0) {
            if (val != ov7670_init[i].val) {
                fprintf(stderr, "Error! Register 0x%02X: expected 0x%02X, got 0x%02X\n",
                        ov7670_init[i].reg, ov7670_init[i].val, val);
                close(fd);
                return -1;
            } else {
                printf("Register 0x%02X set to 0x%02X\n", ov7670_init[i].reg, val);
            }
        } else {
            fprintf(stderr, "Error! Readback of register 0x%02X\n", ov7670_init[i].reg);
            close(fd);
            return -1;
        }
            
        usleep(500);
    }

    close(fd);
    return 0;
}

int main(void) {
    if (configure_sccb() < 0) {
        fprintf(stderr, "Failed to configure SCCB\n");
        return EXIT_FAILURE;
    }
    printf("SCCB configured successfully\n");
    return EXIT_SUCCESS;
}