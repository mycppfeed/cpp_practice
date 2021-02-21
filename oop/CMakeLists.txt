cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(oop_1 oop_1.cpp)
add_test(oop_1_test oop_1)

add_executable(oop_2 oop_2.cpp)
add_test(oop_2_test oop_2)

add_executable(oop_3 oop_3.cpp)
add_test(oop_3_test oop_3)

add_executable(association association.cpp)
add_test(association_test association)

add_executable(VirtualFunction VirtualFunction.cpp)
add_test(VirtualFunction_test VirtualFunction)