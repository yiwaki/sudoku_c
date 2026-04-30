#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <string.h>

namespace py = pybind11;

extern "C" {
#include "sudoku.h"
    void solve(matrix_t *const x, int cell_no, matrix_t *const y);
}

py::array_t<uint16_t> py_solve(py::array_t<uint16_t> input_matrix) {
    py::buffer_info info = input_matrix.request();
    if (info.ndim != 2) {
        throw std::runtime_error("Input should be a 2D array");
    }

    matrix_t start_state;
    for (int i = 0; i < 81; i++) {
        uint16_t val = static_cast<uint16_t *>(info.ptr)[i];
        start_state[i / 9][i % 9] = (val > 0) ? (1 << (val - 1)) : FULL_BIT;
    }

    matrix_t result_state;
    memset(&result_state, 0, sizeof(matrix_t));

    solve(&start_state, 0, &result_state);

    auto result = py::array_t<uint16_t>({9, 9});
    py::buffer_info output_info = result.request();

    for (int i = 0; i < 81; i++) {
        uint16_t bmp = result_state[i / 9][i % 9];
        static_cast<uint16_t *>(output_info.ptr)[i] = (bitmap_t)log2(bmp) + 1;
    }

    return result;
}

PYBIND11_MODULE(sudoku_c, m) {
    m.doc() = "Sudoku solver C extension";
    m.def("solve", &py_solve, "Solve the sudoku puzzle");
}