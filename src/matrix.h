#pragma once

#include <stdbool.h>
#include "bitmap.h"

#define MATRIX_SIZE (9)
#define SQUARE_SIZE (3)

typedef bitmap_t matrix_t[MATRIX_SIZE][MATRIX_SIZE];

#define BLOCK_TYPE_CNT (3)

typedef enum {
    ROW = 1,
    COLUMN,
    SQUARE,
} block_t;

typedef struct {
    int row;
    int col;
} address_t;

void cell_no_to_addr(const int cell_no, address_t *const addr);
int addr_to_block_no(const block_t block_type, const address_t *const addr);
void block_range(const block_t block_type, const int block_no, int row_range[2], int col_range[2]);
