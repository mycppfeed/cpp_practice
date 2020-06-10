cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(threads_0 threads_0.cpp)
target_link_libraries(threads_0 Threads::Threads)
add_test(threads_0_test threads_0)
