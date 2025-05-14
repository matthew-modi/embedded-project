#ifndef BARCODE_DECODER_H
#define BARCODE_DECODER_H

#include <stdint.h>

typedef struct {
    uint8_t b : 5;
    uint8_t g : 6;
    uint8_t r : 5;
} rgb565_t;

// Returns a malloc’d 13-byte string (12 digits + '\0'), or NULL on failure.
// Caller must free() it.
char *process_barcode(rgb565_t *pixels, int len);

#endif // BARCODE_DECODER_H
