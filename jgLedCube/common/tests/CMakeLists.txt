set_property(GLOBAL APPEND PROPERTY
        TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/gtest_serial.cpp
        )

set_property(GLOBAL APPEND PROPERTY
        TEST_LIBS
        common_serial
        )