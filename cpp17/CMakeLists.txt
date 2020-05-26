set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

add_executable(cpp17_if_constexpr cpp17_if_constexpr.cpp)
add_test(cpp17_if_constexpr_t cpp17_if_constexpr)

add_executable(cpp17_structure_bindings cpp17_structure_bindings.cpp)
add_test(cpp17_structure_bindings_t cpp17_structure_bindings)

add_executable(cpp17_vectors cpp17_vectors.cpp)
add_test(cpp17_vectors_t cpp17_vectors)

add_executable(cpp17_array cpp17_array.cpp)
add_test(cpp17_array_t cpp17_array)

add_executable(cpp17_list cpp17_list.cpp)
add_test(cpp17_list_t cpp17_list)
