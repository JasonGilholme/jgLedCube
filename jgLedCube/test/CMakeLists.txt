set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# ADD GOOGLE TEST DIRECTORIES
# TODO: FindGoogletest.cmake??
include_directories( $ENV{REZ_GOOGLETEST_ROOT}/include )
link_directories( $ENV{REZ_GOOGLETEST_ROOT}/lib )

# TEST EXECUTABLE
add_executable(PC_test test.cpp)
target_link_libraries(PC_test jgLedCubeCore gtest pthread)
