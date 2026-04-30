#include "matrix.h"

// Matrix of                     Block No. of each block type
// Cell No.                      Row          Column       Square
// +--------------------------+  +---------+  +---------+  +---------+
// | 0  1  2  3  4  5  6  7  8|  |000000000|  |012345678|  |000111222|
// | 9 10 11 12 13 14 15 16 17|  |111111111|  |012345678|  |000111222|
// |18 19 20 21 22 23 24 25 26|  |222222222|  |012345678|  |000111222|
// |27 28 29 30 31 32 33 34 35|  |333333333|  |012345678|  |333444555|
// |36 37 38 39 40 41 42 43 44|  |444444444|  |012345678|  |333444555|
// |45 46 47 48 49 50 51 52 53|  |555555555|  |012345678|  |333444555|
// |54 55 56 57 58 59 60 61 62|  |666666666|  |012345678|  |666777888|
// |63 64 65 66 67 68 69 70 71|  |777777777|  |012345678|  |666777888|
// |72 73 74 75 76 77 78 79 80|  |888888888|  |012345678|  |666777888|
// +--------------------------+  +---------+  +---------+  +---------+
//
// Address on Matrix: (Row, Column)

void cell_no_to_addr(const int cell_no, address_t *const addr) {
    addr->row = cell_no / MATRIX_SIZE;
    addr->col = cell_no % MATRIX_SIZE;
}

int addr_to_block_no(const block_t block_type, const address_t *const addr) {
    int block_no;
    switch (block_type) {
    case ROW:
        block_no = addr->row;
        break;

    case COLUMN:
        block_no = addr->col;
        break;

    case SQUARE:
        block_no = addr->row / SQUARE_SIZE * SQUARE_SIZE + addr->col / SQUARE_SIZE;
        break;

    default:
        block_no = -1;
        break;
    }
    return block_no;
}

void block_range(const block_t block_type, const int block_no, int row_range[2], int col_range[2]) {
    switch (block_type) {
    case ROW:
        row_range[0] = block_no;
        row_range[1] = row_range[0] + 1;
        col_range[0] = 0;
        col_range[1] = MATRIX_SIZE;
        break;

    case COLUMN:
        row_range[0] = 0;
        row_range[1] = MATRIX_SIZE;
        col_range[0] = block_no;
        col_range[1] = col_range[0] + 1;
        break;

    case SQUARE:
        row_range[0] = block_no / SQUARE_SIZE * SQUARE_SIZE;
        row_range[1] = row_range[0] + SQUARE_SIZE;
        col_range[0] = block_no % SQUARE_SIZE * SQUARE_SIZE;
        col_range[1] = col_range[0] + SQUARE_SIZE;
        break;

    default:
        // noop
        break;
    }
}
