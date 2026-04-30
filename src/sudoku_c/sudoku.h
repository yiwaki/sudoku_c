#ifndef SUDOKU_C_SUDOKU_H
#define SUDOKU_C_SUDOKU_H

#include "matrix.h"

bool check(matrix_t *const x);
bool solve(matrix_t *const x, int n, matrix_t *const y);

#endif // SUDOKU_C_SUDOKU_H
