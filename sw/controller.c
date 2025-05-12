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

#define I2C_BUS        "/dev/i2c-0"
#define SCCB_ADDR      0x21        // OV7670 7-bit (0x42>>1)

// HPS GPIO1 /dev/mem mappings
#define GPIO1_BASE     0xFF709000UL
#define GPIO1_SPAN     0x00001000UL
#define DR_OFFSET      0x00        // Data Register
#define DDR_OFFSET     0x14        // Data Direction Register
#define I2C_CTRL_BIT   (1 << 19)   // GPIO48 = HPS_I2C_CONTROL

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
    {0x12,0x80},{0x11,0x01},{0x6B,0x0A},{0x0C,0x04},
    {0x3E,0x11},{0x12,0x14},{0x13,0xE7},{0x14,0x4A},
    {0x15,0x00},{0x3D,0x98},{0x40,0x10},{0x42,0x08},
    {0x32,0x80},{0x17,0x11},{0x18,0x61},{0x19,0x03},
    {0x1A,0x7B},{0x03,0x06},{0x70,0x3A},{0x71,0x35},
    {0x72,0x11},{0x73,0x00},
    {0x43,0x14},{0x44,0xF0},{0x45,0x45},{0x46,0x61},
    {0x47,0x51},{0x48,0x79},{0x4B,0x09},{0x4F,0x80},
    {0x50,0x80},{0x51,0x00},{0x52,0x22},{0x53,0x5E},
    {0x54,0x80},{0x58,0x9E},
    {0xFF,0xFF}   // end
};

static int switch_i2c_mux_to_hps(void) {
    int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (mem_fd < 0) {
        perror("open /dev/mem");
        return -1;
    }
    void *base = mmap(NULL, GPIO1_SPAN,
                      PROT_READ|PROT_WRITE, MAP_SHARED,
                      mem_fd, GPIO1_BASE);
    if (base == MAP_FAILED) {
        perror("mmap");
        close(mem_fd);
        return -1;
    }

    volatile uint32_t *dr  = (uint32_t *)(base + DR_OFFSET);
    volatile uint32_t *ddr = (uint32_t *)(base + DDR_OFFSET);

    // set GPIO48 as output
    *ddr |= I2C_CTRL_BIT;
    // drive GPIO48 high
    *dr  |= I2C_CTRL_BIT;

    munmap(base, GPIO1_SPAN);
    close(mem_fd);
    return 0;
}

int configure_sccb(void) {
    if (switch_i2c_mux_to_hps() < 0) {
        fprintf(stderr, "Failed to switch I2C mux\n");
        return -1;
    }

    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) {
        perror("open I2C_BUS");
        return -1;
    }

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
        return EXIT_FAILURE;
    }
    printf("SCCB configured successfully\n");
    return EXIT_SUCCESS;
}
