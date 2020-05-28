cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(counting counting.cpp)
add_test(counting_test counting)

add_executable(find find.cpp)
add_test(find_test find)