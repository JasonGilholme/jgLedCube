include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    #
    # find google test
    #
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIR})
    # Set some global properties to gather all the test sources and libs for.
    define_property(GLOBAL PROPERTY TEST_SOURCES BRIEF_DOCS "Global list of test sources" FULL_DOCS "Global list of test sources")
    define_property(GLOBAL PROPERTY TEST_LIBS BRIEF_DOCS "Global list of test libs" FULL_DOCS "Global list of test libs")

    #
    # find & setup Qt
    #
    set(CMAKE_AUTOMOC ON)
    find_package(Qt5 5.8 REQUIRED COMPONENTS Widgets SerialPort REQUIRED)

endif()
