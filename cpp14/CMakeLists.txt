set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

add_executable(cpp14_digitsep cpp14_digitsep.cpp)
add_test(cpp14_digitsep_t cpp14_digitsep)

add_executable(cpp14_constexpr cpp14_constexpr.cpp)
add_test(cpp14_constexpr_t cpp14_constexpr)

add_executable(cpp14_variable_template cpp14_variable_template.cpp)
add_test(cpp14_variable_template_t cpp14_variable_template)

add_executable(cpp14_unique_ptr cpp14_unique_ptr.cpp)
add_test(cpp14_unique_ptr_t cpp14_unique_ptr)

add_executable(cpp14_literals cpp14_literals.cpp)
add_test(cpp14_literals_t cpp14_literals)

add_executable(cpp14_tuple cpp14_tuple.cpp)
add_test(cpp14_tuple_t cpp14_tuple)

add_executable(cpp14_regular_lambda cpp14_regular_lambda.cpp)
add_test(cpp14_regular_lambda_t cpp14_regular_lambda)
