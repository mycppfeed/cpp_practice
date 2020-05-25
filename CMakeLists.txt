project(CPP_Practice LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD_REQUIRED 14)

enable_testing()

# string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
# if (BUILD_TYPE STREQUAL debug)
#     find_package(Catch2 REQUIRED)
#     include(CTest)
#     include(Catch)
#     include(ParseAndAddCatchTests)
# endif()

# add_subdirectory(cstdlib)

# add_executable(prepro prepro/test.cpp)

# add_executable(cpp14_digitsep cpp14/cpp14_digitsep.cpp)
# add_test(cpp14_digitsep_t cpp14_digitsep)

# add_executable(cpp14_constexpr cpp14/cpp14_constexpr.cpp)
# add_test(cpp14_constexpr_t cpp14_constexpr)

add_executable(cpp14_variable_template cpp14/cpp14_variable_template.cpp)
add_test(cpp14_variable_template_t cpp14_variable_template)