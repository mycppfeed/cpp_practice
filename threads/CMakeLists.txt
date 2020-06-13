cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(threads_0 threads_0.cpp)
target_link_libraries(threads_0 Threads::Threads)
add_test(threads_0_test threads_0)


add_executable(mutex_0 mutex_0.cpp)
target_link_libraries(mutex_0 Threads::Threads)
add_test(mutex_0_test mutex_0)

add_executable(condition_variable condition_variable.cpp)
target_link_libraries(condition_variable Threads::Threads)
add_test(condition_variable_test condition_variable)

add_executable(promise promise.cpp)
target_link_libraries(promise Threads::Threads)
add_test(promise_test promise)

add_executable(semaphore semaphore.cpp)
target_link_libraries(semaphore Threads::Threads)
add_test(semaphore_test semaphore)
