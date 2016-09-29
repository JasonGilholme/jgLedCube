set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# FORCE CUBE SPECS FOR TESTING PURPOSES
set(CUBE_X 2)
set(CUBE_Y 2)
set(CUBE_Z 2)
set(N_CHANNELS 3)


# ADD GOOGLE TEST DIRECTORIES
# TODO: FindGoogletest.cmake??
include_directories( $ENV{REZ_GOOGLETEST_ROOT}/include )
link_directories( $ENV{REZ_GOOGLETEST_ROOT}/lib )

# TEST EXECUTABLE
add_executable(cubeTest test.cpp)
target_link_libraries(cubeTest jgLedCubeCore gtest pthread)
