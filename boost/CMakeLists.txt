set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT /Users/user/workspace/boost/_install/install/)
find_package(Boost 1.73 COMPONENTS filesystem REQUIRED)

add_subdirectory(filesystem)
