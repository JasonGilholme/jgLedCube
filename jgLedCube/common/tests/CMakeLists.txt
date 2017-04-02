set_property(GLOBAL APPEND PROPERTY
        GTEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/gtest_serial.cpp
        )

set_property(GLOBAL APPEND PROPERTY
        GTEST_LIBS
        common_serial
        )


set_property(GLOBAL APPEND PROPERTY
        CATCH_TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/catch_test_serial.cpp
        )

set_property(GLOBAL APPEND PROPERTY
        CATCH_TEST_LIBS
        common_serial
        )
