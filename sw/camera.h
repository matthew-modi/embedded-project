#ifndef _CAMERA_H
#define _CAMERA_H

#include <linux/ioctl.h>
#include <linux/types.h>

#define CAMERA_MAGIC 'q'

#define CAMERA_READ_WORD    _IOR(CAMERA_MAGIC, 1, uint32_t *)
#define CAMERA_FIFO_EMPTY   _IOR(CAMERA_MAGIC, 2, int *)

#endif

