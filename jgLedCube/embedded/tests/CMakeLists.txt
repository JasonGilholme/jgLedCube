#add_executable(embedded_tests
#        test.cpp
#        test_core.cpp
#        test_anim.cpp)
#
#target_link_libraries(embedded_tests
#
#        jgLedCubeCore
#        jgLedCubeAnimDebug
#        jgLedCubeAnimSweep
#        jgLedCubeAnimFade
#        jgLedCubeSerialEmbedded
#
#        gtest
#        pthread
#        )


set_property(GLOBAL APPEND PROPERTY
        TEST_SOURCES
#            ${CMAKE_CURRENT_LIST_DIR}/test.cpp
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

#set( TEST_SOURCES
#        ${TEST_SOURCES}
#        test.cpp
#        test_core.cpp
#        test_anim.cpp
#        CACHE
#        INTERNAL
#        FORCE
#        )
#
#set( TEST_LIBS
#        ${TEST_LIBS}
#        jgLedCubeCore
#        jgLedCubeAnimDebug
#        jgLedCubeAnimSweep
#        jgLedCubeAnimFade
#        jgLedCubeSerialEmbedded
#        CACHE
#        INTERNAL
#        FORCE
#        )
