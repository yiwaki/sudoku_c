#include <Python.h>
#include <numpy/arrayobject.h>
#include <numpy/arrayscalars.h>
#include <stdbool.h>
#include <math.h>

#include "sudoku.h"

static PyObject *wrap_solve(PyObject *self, PyObject *args) {
    npy_intp ndim, *dim;
    int type;
    PyArrayObject *x, *y;
    matrix_t *mat_x, *mat_y;

    if (!PyArg_ParseTuple(args, "O!", &PyArray_Type, &x))
        return NULL;

    ndim = PyArray_NDIM(x);
    dim = PyArray_DIMS(x);
    type = PyArray_TYPE(x);
    // printf("type:%d, ndim:%ld, dim0=%ld, dim1=%ld\n", type, ndim, dim[0], dim[1]);

    if (ndim != 2) {
        PyErr_SetString(PyExc_TypeError, "unexpected ndim of array (ndim!=2)");
        return NULL;
    }

    if (dim[0] != MATRIX_SIZE && dim[1] != MATRIX_SIZE) {
        PyErr_SetString(PyExc_TypeError, "unexpected dim of array (dim!=9)");
        return NULL;
    }

    if (type != NPY_UINT16) {
        PyErr_SetString(PyExc_TypeError, "unexpected dtype of array (not numpy.uint16)");
        return NULL;
    }

    y = (PyArrayObject *)PyArray_SimpleNew(ndim, dim, type);
    if (y == NULL) return NULL;

    mat_x = PyArray_DATA(x);
    mat_y = PyArray_DATA(y);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if ((*mat_x)[i][j] == 0) {
                (*mat_x)[i][j] = FULL_BIT;
            } else {
                (*mat_x)[i][j] = 1 << ((*mat_x)[i][j] - 1);
            }
        }
    }

    solve(mat_x, 0, mat_y);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            (*mat_y)[i][j] = log2((*mat_y)[i][j]) + 1;
        }
    }

    return (PyObject *)y;
}

static PyMethodDef methods[] = {
    {"solve", wrap_solve, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "sudoku_c", "Some documentation",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_sudoku_c(void) {
    import_array();
    return PyModule_Create(&module);
}
