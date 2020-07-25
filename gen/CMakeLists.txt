set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

add_executable(constructors constructors.cpp)
add_test(constructors_test constructors)

add_executable(lambda lambda.cpp)
add_test(lambda_test lambda)

add_executable(bare_constructors bare_constructors.cpp)
add_test(bare_constructors_test bare_constructors)

add_executable(alignment alignment.cpp)
add_test(alignment_test alignment)

add_executable(global_initializer_class global_initializer_class.cpp)
add_test(global_initializer_class_test global_initializer_class)

add_executable(operator_overloading operator_overloading.cpp)
add_test(operator_overloading_test operator_overloading)
