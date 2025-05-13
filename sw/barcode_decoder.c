#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define PIXEL_COUNT 640
#define MAX_BITS 1024

// UPC-A digit encodings
const char *L_CODES[10] = {
    "0001101", "0011001", "0010011", "0111101", "0100011",
    "0110001", "0101111", "0111011", "0110111", "0001011"
};
const char *R_CODES[10] = {
    "1110010", "1100110", "1101100", "1000010", "1011100",
    "1001110", "1010000", "1000100", "1001000", "1110100"
};

// Hamming distance
int hamming_distance(const char *a, const char *b, int len) {
    int dist = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) dist++;
    }
    return dist;
}

// Checksum computation
int upca_checksum(const char *digits) {
    int odd = 0, even = 0;
    for (int i = 0; i < 11; i++) {
        int val = digits[i] - '0';
        if (i % 2 == 0) odd += val;
        else even += val;
    }
    int c = (10 - ((odd * 3 + even) % 10)) % 10;
    return c;
}

// Decode 95-bit UPC-A
int decode_upca(const char *bs, char *digits_out, float *conf_out) {
    if (strlen(bs) < 95) return -1;

    // Check guards
    if (hamming_distance(bs, "101", 3) > 2) return -2;
    if (hamming_distance(bs + 45, "01010", 5) > 2) return -3;
    if (hamming_distance(bs + 92, "101", 3) > 2) return -4;

    // Decode left digits
    for (int i = 0; i < 6; i++) {
        const char *seg = bs + 3 + 7 * i;
        int best_digit = -1, min_hd = 8;
        for (int d = 0; d < 10; d++) {
            int hd = hamming_distance(seg, L_CODES[d], 7);
            if (hd < min_hd) {
                min_hd = hd;
                best_digit = d;
            }
        }
        if (min_hd > 3) return -5;
        digits_out[i] = '0' + best_digit;
        conf_out[i] = (7 - min_hd) / 7.0f;
    }

    // Decode right digits
    for (int i = 0; i < 6; i++) {
        const char *seg = bs + 50 + 7 * i;
        int best_digit = -1, min_hd = 8;
        for (int d = 0; d < 10; d++) {
            int hd = hamming_distance(seg, R_CODES[d], 7);
            if (hd < min_hd) {
                min_hd = hd;
                best_digit = d;
            }
        }
        if (min_hd > 3) return -6;
        digits_out[6 + i] = '0' + best_digit;
        conf_out[6 + i] = (7 - min_hd) / 7.0f;
    }

    digits_out[12] = '\0';
    return 0;
}

// Main barcode processor
void process_barcode(uint8_t *scanline) {
    uint8_t binary[PIXEL_COUNT];
    int rle[PIXEL_COUNT];
    int normalized[PIXEL_COUNT];
    char bitstream[MAX_BITS];

    // 1. Smoothing with 5-point box filter
    uint8_t smoothed[PIXEL_COUNT];
    for (int i = 0; i < PIXEL_COUNT; i++) {
        int sum = 0, count = 0;
        for (int j = -2; j <= 2; j++) {
            int idx = i + j;
            if (idx >= 0 && idx < PIXEL_COUNT) {
                sum += scanline[idx];
                count++;
            }
        }
        smoothed[i] = sum / count;
    }

    // 2. Thresholding
    int min = 255, max = 0;
    for (int i = 0; i < PIXEL_COUNT; i++) {
        if (smoothed[i] < min) min = smoothed[i];
        if (smoothed[i] > max) max = smoothed[i];
    }
    int threshold = (min + max) / 2;
    for (int i = 0; i < PIXEL_COUNT; i++) {
        binary[i] = smoothed[i] < threshold ? 1 : 0;
    }

    // 3. Run-length encoding
    int rle_len = 0, cur = binary[0], count = 1;
    for (int i = 1; i < PIXEL_COUNT; i++) {
        if (binary[i] == cur) count++;
        else {
            rle[rle_len++] = count;
            count = 1;
            cur = binary[i];
        }
    }
    rle[rle_len++] = count;

    // 4. Estimate module width
    int sorted[20];
    int run_count = rle_len < 20 ? rle_len : 20;
    memcpy(sorted, rle, sizeof(int) * run_count);
    for (int i = 0; i < run_count - 1; i++) {
        for (int j = i + 1; j < run_count; j++) {
            if (sorted[j] < sorted[i]) {
                int tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }
    int mw = sorted[run_count / 2];
    if (mw < 1) mw = 1;
    if (mw > 10) mw = 10;

    // 5. Normalize RLE to bitstream
    int norm_len = 0;
    cur = binary[0];
    for (int i = 0; i < rle_len; i++) {
        int w = rle[i] / mw;
        if (w < 1) w = 1;
        for (int j = 0; j < w; j++) {
            bitstream[norm_len++] = cur + '0';
        }
        cur = 1 - cur;
    }
    bitstream[norm_len] = '\0';

    // 6. Find best-aligned 95-bit window
    int best_shift = -1, min_hd = 1000;
    for (int s = 0; s <= norm_len - 95; s++) {
        int hd = hamming_distance(bitstream + s, "101", 3) +
                 hamming_distance(bitstream + s + 45, "01010", 5) +
                 hamming_distance(bitstream + s + 92, "101", 3);
        if (hd < min_hd) {
            best_shift = s;
            min_hd = hd;
            if (hd == 0) break;
        }
    }

    if (best_shift < 0) {
        printf("Failed to align barcode\n");
        return;
    }

    char digits[13];
    float confs[12];
    int err = decode_upca(bitstream + best_shift, digits, confs);
    if (err != 0) {
        printf("Decode error %d\n", err);
        return;
    }

    int ck = upca_checksum(digits);
    int actual_ck = digits[11] - '0';
    printf("UPC-A: %s\n", digits);
    printf("Checksum valid? %s\n", (ck == actual_ck ? "Yes" : "No"));

    float avg = 0;
    for (int i = 0; i < 12; i++) avg += confs[i];
    printf("Average confidence: %.2f\n", avg / 12.0);
}
