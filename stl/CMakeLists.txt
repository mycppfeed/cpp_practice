set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

add_executable(seq_vector seq_vector.cpp)
add_test(seq_vector_test seq_vector)

# add_executable(seq_array seq_array.cpp)
# add_test(seq_array_test seq_array)

# add_executable(seq_list seq_list.cpp)
# add_test(seq_list_test seq_list)

# add_executable(ass_set ass_set.cpp)
# add_test(ass_set_test ass_set)

# add_executable(ass_map ass_map.cpp)
# add_test(ass_map_test ass_map)

# set(MODULE_NAME Map_TryEmplace)

# add_executable(${MODULE_NAME} ${MODULE_NAME}.cpp)
# add_test(test_${MODULE_NAME} ${MODULE_NAME})
# set_target_properties(${MODULE_NAME} PROPERTIES CXX_STANDARD 11)
