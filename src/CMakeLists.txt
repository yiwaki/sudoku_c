# cmake -S . -B ../build
# cmake --build ../build --config Debug --target sudoku_main -j 10
cmake_minimum_required(VERSION 3.8.0)
project(sudoku VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(sudoku_main sudoku_main.c sudoku.c bitmap.c matrix.c)
target_compile_features(sudoku_main PRIVATE c_std_11)
target_compile_options(sudoku_main PRIVATE -Wall)
target_link_libraries(sudoku_main m)

add_test(NAME bf_test COMMAND sudoku_main CONFIGULATIONS Debug)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
