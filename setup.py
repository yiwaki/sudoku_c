# python setup.py build_ext --inplace
# python setup.py build_ext --inplace --compiler=mingw32 (for mingw/windows builds)
import numpy
from setuptools import Extension, setup

setup(
    package_dir={"": ""},
    packages=[],
    ext_modules=[
        Extension(
            "sudoku_c",
            sources=[
                "src/wrap_sudoku.c",
                "src/sudoku.c",
                "src/bitmap.c",
                "src/matrix.c",
            ],
            define_macros=[("NPY_NO_DEPRECATED_API", "NPY_1_7_API_VERSION")],
            include_dirs=[numpy.get_include()],
            library_dirs=[],
            libraries=[],
            extra_compile_args=[("-std=c11")],
            extra_link_args=[],
        )
    ],
)
