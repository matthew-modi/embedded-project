#include "barcode_decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIXEL_COUNT 640
#define MAX_BITS     1024

// (Keep your L_CODES, R_CODES, hamming_distance(), upca_checksum(),
//  and decode_upca() exactly as before.)

static uint8_t rgb565_to_gray(rgb565_t p) {
    // Expand bitfields back into full 8-bit channels
    uint8_t r8 = (p.r << 3) | (p.r >> 2);
    uint8_t g8 = (p.g << 2) | (p.g >> 4);
    uint8_t b8 = (p.b << 3) | (p.b >> 2);
    // Weighted grayscale
    return (77 * r8 + 150 * g8 + 29 * b8) >> 8;
}

char *process_barcode(rgb565_t *pixels, int len) {
    if (len < PIXEL_COUNT) return NULL;

    // 1) Convert to grayscale
    uint8_t scanline[PIXEL_COUNT];
    for (int i = 0; i < PIXEL_COUNT; i++)
        scanline[i] = rgb565_to_gray(pixels[i]);

    // 2) Smooth (5-point box)
    uint8_t smoothed[PIXEL_COUNT];
    for (int i = 0; i < PIXEL_COUNT; i++) {
        int sum = 0, cnt = 0;
        for (int j = -2; j <= 2; j++) {
            int idx = i + j;
            if (idx >= 0 && idx < PIXEL_COUNT) {
                sum += scanline[idx];
                cnt++;
            }
        }
        smoothed[i] = sum / cnt;
    }

    // 3) Threshold to binary
    uint8_t binary[PIXEL_COUNT];
    int mn = 255, mx = 0;
    for (int i = 0; i < PIXEL_COUNT; i++) {
        if (smoothed[i] < mn) mn = smoothed[i];
        if (smoothed[i] > mx) mx = smoothed[i];
    }
    int thr = (mn + mx) >> 1;
    for (int i = 0; i < PIXEL_COUNT; i++)
        binary[i] = (smoothed[i] < thr);

    // 4) RLE
    int rle[MAX_BITS], rle_len = 0;
    uint8_t cur = binary[0];
    int cnt = 1;
    for (int i = 1; i < PIXEL_COUNT; i++) {
        if (binary[i] == cur) cnt++;
        else {
            rle[rle_len++] = cnt;
            cnt = 1; cur = binary[i];
        }
    }
    rle[rle_len++] = cnt;

    // 5) Module width via median of first 20
    int sorted[20], runs = rle_len < 20 ? rle_len : 20;
    memcpy(sorted, rle, runs * sizeof(int));
    for (int i = 0; i < runs-1; i++)
      for (int j = i+1; j < runs; j++)
        if (sorted[j] < sorted[i]) {
          int t = sorted[i]; sorted[i] = sorted[j]; sorted[j] = t;
        }
    int mw = sorted[runs/2];
    if (mw < 1) mw = 1; if (mw > 10) mw = 10;

    // 6) Build bitstream
    char bs[MAX_BITS];
    int bs_len = 0;
    cur = binary[0];
    for (int i = 0; i < rle_len; i++) {
        int w = rle[i] / mw;
        if (w < 1) w = 1;
        for (int k = 0; k < w; k++)
            bs[bs_len++] = cur + '0';
        cur = 1 - cur;
    }
    bs[bs_len] = '\0';
    if (bs_len < 95) return NULL;

    // 7) Align to best 95-bit window
    int best_s = -1, best_hd = 1e9;
    for (int s = 0; s <= bs_len - 95; s++) {
        int hd = hamming_distance(  bs + s,     "101",   3)
               + hamming_distance(bs + s+45, "01010", 5)
               + hamming_distance(bs + s+92, "101",   3);
        if (hd < best_hd) { best_hd = hd; best_s = s; if (!hd) break; }
    }
    if (best_s < 0) return NULL;

    // 8) Decode
    char *digits = malloc(13);
    float confs[12];
    if (!digits) return NULL;

    if (decode_upca(bs + best_s, digits, confs) != 0) {
        free(digits);
        return NULL;
    }

    // Optionally check checksum here...
    return digits;
}
