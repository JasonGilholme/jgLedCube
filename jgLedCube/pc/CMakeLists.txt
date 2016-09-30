# TEST EXECUTABLE
add_executable(PC_test test.cpp)
target_link_libraries(PC_test jgLedCubeCore gtest pthread)
