cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(parcel_decoder parcel_decoder.cpp)
add_test(parcel_decoder_test parcel_decoder ${CMAKE_CURRENT_SOURCE_DIR}/wifi.dat)