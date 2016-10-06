set_property(GLOBAL APPEND PROPERTY
        TEST_SOURCES
            ${CMAKE_CURRENT_LIST_DIR}/test_core.cpp
            ${CMAKE_CURRENT_LIST_DIR}/test_anim.cpp
        )

set_property(GLOBAL APPEND PROPERTY
        TEST_LIBS
            jgLedCubeCore
            jgLedCubeAnimDebug
            jgLedCubeAnimSweep
            jgLedCubeAnimFade
            jgLedCubeSerialEmbedded
        )
