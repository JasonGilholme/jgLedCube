if ( CUBE_TARGET_PLATFORM STREQUAL desktop )
    # Set cube dimensions for
    add_definitions(-DLED_CUBE_X_DIMENSION=4)
    add_definitions(-DLED_CUBE_Y_DIMENSION=4)
    add_definitions(-DLED_CUBE_Z_DIMENSION=4)
    add_definitions(-DLED_CUBE_N_CHANNELS=3)
    add_definitions(-DLED_CUBE_VERSION=1234)
    add_definitions(-DLED_CUBE_UID=1234)
endif()

add_subdirectory(common)
add_subdirectory(controllers)
add_subdirectory(cubes)
add_subdirectory(python)

if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    # GTest
    get_property(GTEST_SOURCES GLOBAL PROPERTY GTEST_SOURCES)
    get_property(GTEST_LIBS GLOBAL PROPERTY GTEST_LIBS)
    add_executable(google_tests gtest.cpp ${GTEST_SOURCES})
    target_link_libraries(google_tests -pthread ${GTEST_LIBRARY} ${GTEST_LIBS})

    # Catch Test
    get_property(CATCH_TEST_SOURCES GLOBAL PROPERTY CATCH_TEST_SOURCES)
    get_property(CATCH_TEST_LIBS GLOBAL PROPERTY CATCH_TEST_LIBS)
    add_executable(catch_tests catch_test.cpp ${CATCH_TEST_SOURCES})
    target_link_libraries(catch_tests ${CATCH_TEST_LIBS})
endif()