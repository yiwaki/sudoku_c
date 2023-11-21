#include "bitmap.h"

#include <string.h>

int split_single_bit(const bitmap_t bit, bitmap_t bits[BITMAP_DIGIT]) {
    memset(bits, 0, sizeof(bitmap_t) * BITMAP_DIGIT);

    int cnt = 0;
    for (int i = 0; i < BITMAP_DIGIT; i++) {
        bitmap_t target_bit = 1 << i;
        if (bit & target_bit) {
            bits[cnt] = target_bit;
            cnt++;
        }
    }
    return cnt;
}

int popcount(const bitmap_t bit) {
    int cnt = 0;
    for (int i = 0; i < BITMAP_DIGIT; i++) {
        bitmap_t target_bit = 1 << i;
        if (bit & target_bit) {
            cnt++;
        }
    }
    return cnt;
}

char *to_binary(const bitmap_t bmp, char bin_str[BITMAP_DIGIT]) {
    char *ptr = bin_str;
    for (int i = 0; i < BITMAP_DIGIT; i++) {
        if (bmp & (0b100000000 >> i)) {
            *ptr = '1';
        } else {
            *ptr = '0';
        }
        ptr++;
    }
    bin_str[BITMAP_DIGIT] = '\0';

    return bin_str;
}
