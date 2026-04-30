from setuptools import setup, Extension, find_packages
import pybind11


# すべてのCファイルをコンパイル対象に含める
ext_modules = [
    Extension(
        "sudoku_c.sudoku_c",
        sources=[
            "src/sudoku_c/bridge.cpp",
            "src/sudoku_c/sudoku.c",
            "src/sudoku_c/matrix.c",
            "src/sudoku_c/bitmap.c"
        ],
        include_dirs=[
            pybind11.get_include(),
            "src/sudoku_c",
        ],
        language='c++'
    ),
]


setup(
    name="sudoku_c",
    version="0.1.0",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    ext_modules=ext_modules,
    package_data={
        "sudoku_c": ["*.pyi", "py.typed"],
    },
    zip_safe=False,
)