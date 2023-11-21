# cmake -S . -B ../build
# cmake --build ../build --config Debug --target bruteforce_main -j 10
cmake_minimum_required(VERSION 3.8.0)
project(sudoku VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(bruteforce_main bruteforce_main.c bruteforce.c bitmap.c matrix.c)
target_compile_features(bruteforce_main PRIVATE c_std_11)
target_compile_options(bruteforce_main PRIVATE -Wall)

add_test(NAME bf_test COMMAND bruteforce_main CONFIGULATIONS Debug)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
