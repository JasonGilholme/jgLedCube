# Set some global properties to gather all the test sources and libs for.
define_property(GLOBAL PROPERTY TEST_SOURCES BRIEF_DOCS "Global list of test sources" FULL_DOCS "Global list of test sources")
define_property(GLOBAL PROPERTY TEST_LIBS BRIEF_DOCS "Global list of test libs" FULL_DOCS "Global list of test libs")


add_subdirectory(common)
#add_subdirectory(desktop)
add_subdirectory(embedded)


if ( NOT DEFINED BUILD_EMBEDDED )

    get_property(_TEST_SOURCES GLOBAL PROPERTY TEST_SOURCES)
    get_property(_TEST_LIBS GLOBAL PROPERTY TEST_LIBS)

    add_executable( c_tests test.cpp ${_TEST_SOURCES} )
    target_link_libraries( c_tests ${_TEST_LIBS} gtest pthread )

endif()
