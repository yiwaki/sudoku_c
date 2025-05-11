# python setup.py build
# python setup.py build --compiler=mingw32 (for mingw/windows)
# import numpy as np
from setuptools import Extension, setup

setup(
    name="sudoku_c",
    version="1.0.0",
    ext_modules=[
        Extension(
            name="sudoku_c",
            sources=[
                "src/lib.c",
                "src/sudoku.c",
                "src/bitmap.c",
                "src/matrix.c",
            ],
            # include_dirs=[np.get_include()],
            include_dirs=["src", ".venv/Lib/site-packages/numpy/_core/include"],
        ),
    ],
)
