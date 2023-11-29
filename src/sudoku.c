#include "sudoku.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitmap.h"
#include "matrix.h"

bool _done(matrix_t *const x) {
    for (int block_type = 0; block_type < BLOCK_TYPE_CNT; block_type++) {
        for (int block_no = 0; block_no < MATRIX_SIZE; block_no++) {
            int row_range[2], col_range[2];
            block_range(block_type, block_no, row_range, col_range);

            bitmap_t bmp = 0;
            for (int row_no = row_range[0]; row_no < row_range[1]; row_no++) {
                for (int col_no = col_range[0]; col_no < col_range[1]; col_no++) {
                    bmp |= (*x)[row_no][col_no];

                    if (popcount((*x)[row_no][col_no]) > 1) return false;
                }
            }

            if (bmp != FULL_BIT) return false;
        }
    }
    return true;
}

bool _prune_by_pivot(matrix_t *const x, address_t *const pivot, const bitmap_t bit) {
    for (int block_type = 0; block_type < BLOCK_TYPE_CNT; block_type++) {
        int block_no = addr_to_block_no(block_type, pivot);

        int row_range[2], col_range[2];
        block_range(block_type, block_no, row_range, col_range);

        for (int row_no = row_range[0]; row_no < row_range[1]; row_no++) {
            for (int col_no = col_range[0]; col_no < col_range[1]; col_no++) {
                if (row_no == pivot->row && col_no == pivot->col) {
                    (*x)[row_no][col_no] = bit;
                    continue;
                }

                (*x)[row_no][col_no] &= (~bit);

                if ((*x)[row_no][col_no] == 0) return false;
            }
        }
    }

    return test_bitmap_by_addr(x, pivot);
}

void bruteforce(matrix_t *const x, int cell_no, matrix_t *const y) {
    if (cell_no >= MATRIX_SIZE * MATRIX_SIZE) return;

    address_t addr;
    cell_no_to_addr(cell_no, &addr);

    bitmap_t bits[BITMAP_DIGIT];
    int bit_cnt = split_single_bit((*x)[addr.row][addr.col], bits);

    for (int i = 0; i < bit_cnt; i++) {
        memcpy(y, x, sizeof(matrix_t));
        if (!_prune_by_pivot(y, &addr, bits[i])) continue;

        matrix_t work;
        bruteforce(y, cell_no + 1, &work);

        if (_done(&work)) {
            memcpy(y, work, sizeof(matrix_t));
            return;
        }
    }
}
