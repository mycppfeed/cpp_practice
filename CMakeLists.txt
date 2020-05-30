project(CPP_Practice LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)
enable_testing()

# -fsanitize=memory

if (CMAKE_GENERATOR STREQUAL "Xcode")
    set(CMAKE_XCODE_GENERATE_SCHEME ON)
    set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER ON)
    set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN ON)
    set(CMAKE_XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER ON)
    set(CMAKE_XCODE_SCHEME_MALLOC_SCRIBBLE ON)
    set(CMAKE_XCODE_SCHEME_ZOMBIE_OBJECTS ON)
else()
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined" )
    set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined" )
endif()

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
