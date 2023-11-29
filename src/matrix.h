#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include "bitmap.h"

#define MATRIX_SIZE (9)
#define SQUARE_SIZE (3)

typedef bitmap_t matrix_t[MATRIX_SIZE][MATRIX_SIZE];

typedef enum {
    Row = 0,
    Column,
    Square,
    BLOCK_TYPE_CNT  // count of kinds of block type (Row/Column/Square)
} block_t;

typedef struct {
    int row;
    int col;
} address_t;

void cell_no_to_addr(const int cell_no, address_t *const addr);
int addr_to_block_no(const block_t block_type, const address_t *const addr);
void block_range(const block_t block_type, const int block_no, int row_range[2], int col_range[2]);
bool test_bitmap_by_addr(matrix_t *const x, address_t *const addr);

#endif  // MATRIX_H
