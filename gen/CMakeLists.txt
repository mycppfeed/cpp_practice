set(CMAKE_CXX_STANDARD 14)
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
