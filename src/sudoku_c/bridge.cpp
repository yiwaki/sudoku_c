#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <string.h>

extern "C" {
#include "sudoku.h"
}

namespace py = pybind11;

bool py_check(py::array_t<uint16_t> input_matrix) {
    py::buffer_info info = input_matrix.request();
    if (info.ndim != 2 || info.shape[0] != MATRIX_SIZE || info.shape[1] != MATRIX_SIZE) {
        throw std::runtime_error("Input array must be of type uint16(9,9)");
    }

    matrix_t matrix;
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        uint16_t val = static_cast<uint16_t *>(info.ptr)[i];
        matrix[i / MATRIX_SIZE][i % MATRIX_SIZE] = (val > 0) ? (1 << (val - 1)) : FULL_BIT;
    }

    return check(&matrix);
}

py::array_t<uint16_t> py_solve(py::array_t<uint16_t> input_matrix) {
    py::buffer_info info = input_matrix.request();
    if (info.ndim != 2 || info.shape[0] != MATRIX_SIZE || info.shape[1] != MATRIX_SIZE) {
        throw std::runtime_error("Input array must be of type uint16(9,9)");
    }

    matrix_t start_state;
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        uint16_t val = static_cast<uint16_t *>(info.ptr)[i];
        start_state[i / MATRIX_SIZE][i % MATRIX_SIZE]
            = (val > 0) ? (1 << (val - 1)) : FULL_BIT;
    }

    matrix_t result_state;
    memset(&result_state, 0, sizeof(matrix_t));

    if (!(solve(&start_state, 0, &result_state))) {
        throw std::runtime_error("No solution found");
    }

    auto result = py::array_t<uint16_t>({MATRIX_SIZE, MATRIX_SIZE});
    py::buffer_info output_info = result.request();

    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        uint16_t bmp = result_state[i / MATRIX_SIZE][i % MATRIX_SIZE];
        static_cast<uint16_t *>(output_info.ptr)[i] = (bitmap_t)log2(bmp) + 1;
    }

    return result;
}

PYBIND11_MODULE(sudoku_c, m) {
    m.doc() = "Sudoku solver C extension";
    m.def("check", &py_check, "Check if the result is valid");
    m.def("solve", &py_solve, "Solve the sudoku puzzle");
}