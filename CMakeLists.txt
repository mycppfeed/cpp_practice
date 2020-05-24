project(CPP_Practice LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)

string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
if (BUILD_TYPE STREQUAL debug)
    find_package(Catch2 REQUIRED)
    include(CTest)
    include(Catch)
    include(ParseAndAddCatchTests)
endif()

add_subdirectory(cstdlib)