# TEST EXECUTABLE
add_executable(PC_tests test.cpp test_core.cpp test_anim.cpp)
target_link_libraries(PC_tests

        jgLedCubeCore
        jgLedCubeAnimDebug
        jgLedCubeAnimSweep

        gtest
        pthread
        )
