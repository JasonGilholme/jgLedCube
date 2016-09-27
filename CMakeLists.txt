cmake_minimum_required(VERSION 3.6)
project(led_cube)

# CONFIGURE CUBE SPECS HERE
add_definitions( -DLED_CUBE_X_DIMENSION=4 )
add_definitions( -DLED_CUBE_Y_DIMENSION=4 )
add_definitions( -DLED_CUBE_Z_DIMENSION=4 )
add_definitions( -DLED_CUBE_N_CHANNELS=1 )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# ADD GOOGLE TEST DIRECTORIES
include_directories( $ENV{REZ_GOOGLETEST_ROOT}/include )
link_directories( $ENV{REZ_GOOGLETEST_ROOT}/lib )


# THE MAIN LIBRARY FOR THE LED CUBE
add_library(jgLedCube ledcube/core.cpp)

# TEST EXECUTABLE
add_executable(cubeTest ledcube/test.cpp)
target_link_libraries(cubeTest jgLedCube gtest pthread)
