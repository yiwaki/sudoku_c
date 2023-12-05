#pragma once

#define BITMAP_DIGIT (9)
#define FULL_BIT (0b111111111)

typedef unsigned short bitmap_t;

int split_single_bit(const bitmap_t bit, bitmap_t bits[BITMAP_DIGIT]);
int popcount(const bitmap_t bit);
char *to_binary(const bitmap_t bmp, char bin_str[BITMAP_DIGIT]);
