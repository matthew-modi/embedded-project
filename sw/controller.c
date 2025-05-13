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
    
    {0x11, 0x01}, // CLKRC: divide input clock by 2
    {0x6B, 0x0A}, // DBLV: enable 4× PLL, PCLK ÷2
    {0x0C, 0x04}, // COM3: disable scaling, raw output
    {0x3E, 0x11}, // COM14: PCLK÷2 on output latch
    {0x12, 0x14}, // COM7: select RGB output, disable colour bar
    {0x13, 0xE7}, // COM8: enable AGC, AWB, AEC
    {0x14, 0x4A}, // COM9: set AGC ceiling to 64× gain
    {0x15, 0x00}, // COM10: normal PCLK, VSYNC/HREF polarity
    {0x3D, 0x98}, // COM13: enable gamma correction
    {0x40, 0x10}, // COM16: disable AWB & edge auto
    {0x42, 0x08}, // COM17: disable DSP colourbar
    {0x32, 0x80}, // HREF: enable long HREF timing
    {0x17, 0x11}, // HSTART: start of active window (MSBs)
    {0x18, 0x61}, // HSTOP: end of active window (MSBs)
    {0x19, 0x03}, // VSTRT: start of active window (MSBs)
    {0x1A, 0x7B}, // VSTOP: end of active window (MSBs)
    {0x03, 0x06}, // VREF: divide window vertically
    {0x70, 0x3A}, // SCALING_XSC: horizontal scaling coefficient
    {0x71, 0x35}, // SCALING_YSC: vertical scaling coefficient
    {0x72, 0x11}, // SCALING_DCWCTR: downsample control
    {0x73, 0x00}, // SCALING_PCLK_DIV: disable PCLK divide

    // AWB gain controls
    {0x43, 0x14}, // RED gain MSB
    {0x44, 0xF0}, // RED gain LSB
    {0x45, 0x45}, // GREEN gain MSB
    {0x46, 0x61}, // GREEN gain LSB
    {0x47, 0x51}, // BLUE gain MSB
    {0x48, 0x79}, // BLUE gain LSB
    {0x4B, 0x09}, // GAIN: global analog gain control

    // Banding filter
    {0x4F, 0x80}, // MTX1[7:0]
    {0x50, 0x80}, // MTX1[15:8]
    {0x51, 0x00}, // MTX2[7:0]
    {0x52, 0x22}, // MTX2[15:8]
    {0x53, 0x5E}, // MTX3[7:0]
    {0x54, 0x80}, // MTX3[15:8]
    {0x58, 0x9E}, // COM24: banding filter MSB

    {0xFF, 0xFF}  // End marker
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