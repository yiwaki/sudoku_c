# python setup.py build_ext --inplace
# python setup.py build_ext --inplace --compiler=mingw32 (for mingw/windows)
import numpy as np
from setuptools import Extension, setup

setup(
    name="sudoku_c",
    version="1.0.0",
    package_dir={"": ""},
    packages=[],
    # install_requires=["numpy"],
    ext_modules=[
        Extension(
            "sudoku_c",
            sources=[
                "src/lib.c",
                "src/sudoku.c",
                "src/bitmap.c",
                "src/matrix.c",
            ],
            # define_macros=[("NPY_NO_DEPRECATED_API", "NPY_1_7_API_VERSION")],
            include_dirs=[np.get_include()],
            library_dirs=[],
            libraries=[],
            extra_compile_args=[],
            extra_link_args=[],
        )
    ],
)
