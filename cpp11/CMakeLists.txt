set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp11_move_semantics cpp11_move_semantics.cpp)
add_test(cpp11_move_semantics_t cpp11_move_semantics)
