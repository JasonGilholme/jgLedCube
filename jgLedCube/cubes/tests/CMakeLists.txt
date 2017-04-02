set_property(GLOBAL APPEND PROPERTY
        GTEST_SOURCES
            ${CMAKE_CURRENT_LIST_DIR}/test_core.cpp
            ${CMAKE_CURRENT_LIST_DIR}/test_anim.cpp
        )

set_property(GLOBAL APPEND PROPERTY
        GTEST_LIBS
            cube_core
            anim_debug
            anim_sweep
            anim_fade
            cube_serial
        )
