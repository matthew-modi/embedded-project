#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>

#define I2C_BUS     "/dev/i2c-1"
#define SCCB_ADDR   0x21    // OV7670 7-bit (0x42>>1)

/** Write one byte to camera register via SCCB/I²C */
static int write_reg(int fd, uint8_t reg, uint8_t val) {
    if (ioctl(fd, I2C_SLAVE, SCCB_ADDR) < 0) {
        perror("I2C_SLAVE");
        return -1;
    }
    if (i2c_smbus_write_byte_data(fd, reg, val) < 0) {
        perror("write_byte_data");
        return -1;
    }
    return 0;
}

/** Read one byte back (for verification) */
static int read_reg(int fd, uint8_t reg, uint8_t *val) {
    if (ioctl(fd, I2C_SLAVE, SCCB_ADDR) < 0) {
        perror("I2C_SLAVE");
        return -1;
    }
    int r = i2c_smbus_read_byte_data(fd, reg);
    if (r < 0) {
        perror("read_byte_data");
        return -1;
    }
    *val = (uint8_t)r;
    return 0;
}

/** OV7670 init table covering format, clock, scaling, color, AWB, banding, etc. */
struct regval { uint8_t reg, val; };
static const struct regval ov7670_init[] = {
    {0x12, 0x80}, // COM7: reset all 
    {0x11, 0x01}, // CLKRC: prescale /2 
    {0x6B, 0x0A}, // DBLV: PLL×4, PCLK÷2 
    {0x0C, 0x04}, // COM3: scaling off 
    {0x3E, 0x11}, // COM14: pclk/2 on latch 
    {0x12, 0x14}, // COM7: RGB, no colorbar 
    {0x13, 0xE7}, // COM8: AGC/AWB/AEC on 
    {0x14, 0x4A}, // COM9: AGC ceiling = 64x 
    {0x15, 0x00}, // COM10: PCLK free-run, normal polarity 
    {0x3D, 0x98}, // COM13: gamma enable 
    {0x40, 0x10}, // COM16: AWB/edge-auto off 
    {0x42, 0x08}, // COM17: DSP colorbar off 
    {0x32, 0x80}, // HREF: enable long HREF 
    {0x17, 0x11}, // HSTART 
    {0x18, 0x61}, // HSTOP 
    {0x19, 0x03}, // VSTRT 
    {0x1A, 0x7B}, // VSTOP 
    {0x03, 0x06}, // VREF: divide window 
    {0x70, 0x3A}, // SCALING_XSC 
    {0x71, 0x35}, // SCALING_YSC 
    {0x72, 0x11}, // SCALING_DCWCTR 
    {0x73, 0x00}, // SCALING_PCLK_DIV 
    // AWB control (tune as needed)
    {0x43, 0x14}, {0x44, 0xF0}, {0x45, 0x45}, {0x46, 0x61},
    {0x47, 0x51}, {0x48, 0x79}, {0x4B, 0x09},
    {0x4F, 0x80}, {0x50, 0x80}, {0x51, 0x00}, {0x52, 0x22},
    {0x53, 0x5E}, {0x54, 0x80}, {0x58, 0x9E}, // banding filter 
    {0xFF, 0xFF}  // end marker
};

int configure_sccb(void) {
    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) { perror("open"); return 1; }

    // Apply init table
    for (int i = 0; ov7670_init[i].reg != 0xFF; i++) {
        if (write_reg(fd, ov7670_init[i].reg, ov7670_init[i].val) < 0)
            return 1; // error writing register
        usleep(500);
    }

    // verify a few registers
    uint8_t v;
    read_reg(fd, 0x0A, &v);  // PID MSB
    printf("PID MSB = 0x%02X\n", v);

    close(fd);
    return 0;
}

int main(void) {
    if (configure_sccb() != 0) {
        fprintf(stderr, "Failed to configure SCCB\n");
        return 1;
    }

    printf("SCCB configured successfully\n");
    return 0;

    
}