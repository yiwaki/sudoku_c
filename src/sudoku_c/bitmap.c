#include "bitmap.h"

#include <string.h>

void split_single_bit(const bitmap_t bit, int *const cnt, bitmap_t bits[BITMAP_DIGIT]) {
    memset(bits, 0, sizeof(bitmap_t) * BITMAP_DIGIT);

    *cnt = 0;
    for (int i = 0; i < BITMAP_DIGIT; i++) {
        bitmap_t target_bit = 1 << i;
        if (bit & target_bit) {
            bits[*cnt] = target_bit;
            (*cnt)++;
        }
    }
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
