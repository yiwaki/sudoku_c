import platform

import pybind11  # pyright: ignore[reportMissingImports]
from setuptools import (  # pyright: ignore[reportMissingModuleSource]
    Extension,
    find_packages,
    setup,
)

extra_args = []
if platform.system() == "Windows":
    # MSVC用の設定
    extra_args += ["/wd4819", "/O2", "/utf-8"]
else:
    # Mac/Linux (GCC/Clang) 用の設定
    extra_args += ["-O3"]

# すべてのCファイルをコンパイル対象に含める
ext_modules = [
    Extension(
        "sudoku_c.sudoku_c",
        sources=[
            "src/sudoku_c/bridge.cpp",
            "src/sudoku_c/sudoku.c",
            "src/sudoku_c/matrix.c",
            "src/sudoku_c/bitmap.c",
        ],
        include_dirs=[
            pybind11.get_include(),
            "src/sudoku_c",
        ],
        language="c++",
        extra_compile_args=extra_args,
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
