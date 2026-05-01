#ifndef SUDOKU_C_SUDOKU_H
#define SUDOKU_C_SUDOKU_H

#include "matrix.h"

bool check(const matrix_t *const x);
bool solve(const matrix_t *const x, int cell_no, matrix_t *const y);

#endif // SUDOKU_C_SUDOKU_H
