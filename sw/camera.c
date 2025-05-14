#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include "camera.h"

// Define locally if not using HAL includes
#define ALTERA_AVALON_FIFO_DATA_REG           0
#define ALTERA_AVALON_FIFO_STATUS_REG         1
#define ALTERA_AVALON_FIFO_STATUS_EMPTY_MASK  (1 << 1)

#define SCANLINE_OFFSET      (ALTERA_AVALON_FIFO_DATA_REG * 4)
#define FIFO_EMPTY_OFFSET    (ALTERA_AVALON_FIFO_STATUS_REG * 4)
#define DRIVER_NAME "camera"

// #define SCANLINE_OFFSET       0x000  // FIFO read port 
// #define FIFO_EMPTY_OFFSET     0x004  // FIFO istatus

struct camera_dev {
    struct resource res;
    void __iomem *virtbase;
    void __iomem *scanline_base;
    void __iomem *fifo_empty_base;
} dev;

static long camera_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch (cmd) {
    case CAMERA_READ_WORD: {
        uint32_t word = ioread32(dev.scanline_base);
        if (copy_to_user((uint32_t *)arg, &word, sizeof(uint32_t)))
            return -EFAULT;
        break;
    }

    case CAMERA_FIFO_EMPTY: {
        uint32_t status = ioread32(dev.fifo_empty_base);
        int empty = (status >> 1) & 0x1;  // Bit 1 is EMPTY flag
        if (copy_to_user((int *)arg, &empty, sizeof(int)))
            return -EFAULT;
        break;
    }

    default:
        return -EINVAL;
    }

    return 0;
}

static const struct file_operations camera_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = camera_ioctl,
};

static struct miscdevice camera_misc_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name  = DRIVER_NAME,
    .fops  = &camera_fops,
};

static int __init camera_probe(struct platform_device *pdev)
{
    int ret;

    ret = misc_register(&camera_misc_device);
    if (ret)
        return ret;

    ret = of_address_to_resource(pdev->dev.of_node, 0, &dev.res);
    if (ret)
        goto fail_deregister;

    if (!request_mem_region(dev.res.start, resource_size(&dev.res), DRIVER_NAME)) {
        ret = -EBUSY;
        goto fail_deregister;
    }

    dev.virtbase = of_iomap(pdev->dev.of_node, 0);
    if (!dev.virtbase) {
        ret = -ENOMEM;
        goto fail_release;
    }

    dev.scanline_base = dev.virtbase + SCANLINE_OFFSET;
    dev.fifo_empty_base = dev.virtbase + FIFO_EMPTY_OFFSET;

    pr_info(DRIVER_NAME ": probe successful\n");
    return 0;

fail_release:
    release_mem_region(dev.res.start, resource_size(&dev.res));
fail_deregister:
    misc_deregister(&camera_misc_device);
    return ret;
}

static int camera_remove(struct platform_device *pdev)
{
    iounmap(dev.virtbase);
    release_mem_region(dev.res.start, resource_size(&dev.res));
    misc_deregister(&camera_misc_device);
    return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id camera_of_match[] = {
    { .compatible = "csee4840,camera-1.0" },
    {},
};
MODULE_DEVICE_TABLE(of, camera_of_match);
#endif

static struct platform_driver camera_driver = {
    .driver = {
        .name = DRIVER_NAME,
        .owner = THIS_MODULE,
        .of_match_table = of_match_ptr(camera_of_match),
    },
    .remove = __exit_p(camera_remove),
};

static int __init camera_init(void)
{
    pr_info(DRIVER_NAME ": init\n");
    return platform_driver_probe(&camera_driver, camera_probe);
}

static void __exit camera_exit(void)
{
    platform_driver_unregister(&camera_driver);
    pr_info(DRIVER_NAME ": exit\n");
}

module_init(camera_init);
module_exit(camera_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ananya Haritsa, Columbia University");
MODULE_DESCRIPTION("Camera driver for polling and stream reading");
