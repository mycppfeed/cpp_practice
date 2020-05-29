project(CPP_Practice LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)
enable_testing()

# add_subdirectory(cpp11)
# add_subdirectory(cpp14)
# add_subdirectory(cpp17)
# add_subdirectory(stl)
# add_subdirectory(gen)
add_subdirectory(algorithms)

# string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
# if (BUILD_TYPE STREQUAL debug)
#     find_package(Catch2 REQUIRED)
#     include(CTest)
#     include(Catch)
#     include(ParseAndAddCatchTests)
# endif()

# add_subdirectory(cstdlib)

# add_executable(prepro prepro/test.cpp)
