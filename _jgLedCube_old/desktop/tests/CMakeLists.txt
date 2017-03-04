add_executable(desktop_tests
        test.cpp
        test_serial.cpp)

target_link_libraries(desktop_tests

        jgLedCubeSerial


        gtest
        pthread
        )
