add_executable(common_tests
        test.cpp
        test_serial.cpp)

target_link_libraries(common_tests

        jgLedCubeSerial

        gtest
        pthread
        )


set_property(GLOBAL APPEND PROPERTY
        TEST_SOURCES
#        ${CMAKE_CURRENT_LIST_DIR}/test.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_serial.cpp
        )

set_property(GLOBAL APPEND PROPERTY
        TEST_LIBS
        jgLedCubeSerial
        )
