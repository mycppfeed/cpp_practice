cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(0_non_modifying 0_non_modifying.cpp)
add_test(0_non_modifying_test 0_non_modifying)

add_executable(1_1_modifying 1_1_modifying.cpp)
add_test(1_1_modifying_test 1_1_modifying)
