#include "sudoku.h"
#include "bitmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

int main(void) {
    // matrix_t x = {
    //     {511, 511,   8, 511,  16, 511, 511, 511,   1},
    //     {511, 511,  32, 511, 511, 511, 511,   4, 511},
    //     { 16,   4, 511,  64, 511, 511, 511, 511, 128},
    //     {  1,   2, 511, 511,  32, 511, 511, 128, 511},
    //     {511, 511,   4, 511, 511, 511, 511, 511, 511},
    //     {511, 511, 511, 511, 511, 256, 511, 511,  64},
    //     {  8, 511, 511, 511, 511, 511, 511, 511, 511},
    //     {128,  16, 511, 511,   1, 511, 511,   2, 511},
    //     {511, 511, 511,  32, 511, 511,   1, 511, 511}
    // };
    matrix_t x = {
        {1,3,0,7,9,0,0,4,5},
        {0,0,5,0,0,0,0,0,6},
        {2,0,0,0,8,0,9,0,0},
        {3,1,0,4,6,5,8,0,0},
        {4,0,0,0,0,0,0,0,2},
        {0,0,7,9,3,2,0,1,4},
        {0,0,3,0,7,0,0,0,8},
        {7,0,0,0,0,0,3,0,0},
        {8,9,0,0,5,4,0,2,1}
    };

    printf("Problem:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%u ", x[i][j]);
            if (x[i][j] == 0) {
                x[i][j] = FULL_BIT;
            } else {
                x[i][j] = 1 << (x[i][j] - 1);
            }
        }
        printf("\n");
    }

    struct timeval start, end;
    gettimeofday(&start, 0);

    matrix_t y;
    solve(&x, 0, &y);

    gettimeofday(&end, 0);

    printf("Solution:\n");
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            printf("%1.0f ", log2(y[row][col]) + 1);
        }
        printf("\n");
    }

    printf("elapsed time: %f\n", (end.tv_usec - start.tv_usec) * 1E-9);

    return EXIT_SUCCESS;
}
