add_subdirectory(common)
add_subdirectory(controllers)

if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    get_property(GTEST_SOURCES GLOBAL PROPERTY GTEST_SOURCES)
    get_property(GTEST_LIBS GLOBAL PROPERTY GTEST_LIBS)
    # GTest
    add_executable(google_tests gtest.cpp ${GTEST_SOURCES})
    target_link_libraries(google_tests -pthread ${GTEST_LIBRARY} ${GTEST_LIBS})

    # Catch Test
    get_property(CATCH_TEST_SOURCES GLOBAL PROPERTY CATCH_TEST_SOURCES)
    get_property(CATCH_TEST_LIBS GLOBAL PROPERTY CATCH_TEST_LIBS)
    add_executable(catch_tests catch_test.cpp ${CATCH_TEST_SOURCES})
    target_link_libraries(catch_tests ${CATCH_TEST_LIBS})
else()
    add_subdirectory(cubes)
endif()
