# cmake -S . -B ../build
# cmake --build ../build --config Debug --target sudoku -j 10
cmake_minimum_required(VERSION 3.8.0)
project(sudoku VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(sudoku main.c sudoku.c bitmap.c matrix.c)
target_compile_features(sudoku PRIVATE c_std_11)
target_compile_options(sudoku PRIVATE -Wall)
target_link_libraries(sudoku m)

add_test(NAME bf_test COMMAND sudoku CONFIGULATIONS Debug)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
