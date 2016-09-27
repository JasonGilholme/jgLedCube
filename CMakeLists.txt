cmake_minimum_required(VERSION 3.6)
project(led_cube)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# ADD GOOGLE TEST DIRECTORIES
include_directories( $ENV{GOOGLETEST_ROOT}/include )
link_directories( $ENV{GOOGLETEST_ROOT}/lib )

# THE MAIN LIBRARY FOR THE LED CUBE
add_library(jgLedCube ledcube/core.cpp)

# TEST EXECUTABLE
add_executable(cubeTest ledcube/test.cpp)
target_link_libraries(cubeTest jgLedCube gtest pthread)
