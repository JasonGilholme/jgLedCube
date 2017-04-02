include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    #
    # find google test
    #
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIR})
    define_property(GLOBAL PROPERTY GTEST_SOURCES BRIEF_DOCS "Global list of test sources" FULL_DOCS "Global list of test sources")
    define_property(GLOBAL PROPERTY GTEST_LIBS BRIEF_DOCS "Global list of test libs" FULL_DOCS "Global list of test libs")

    #
    # setup catch test
    #
    include_directories($ENV{REZ_CATCH_ROOT}/include)
    define_property(GLOBAL PROPERTY CATCH_TEST_SOURCES BRIEF_DOCS "Global list of test sources" FULL_DOCS "Global list of test sources")
    define_property(GLOBAL PROPERTY CATCH_TEST_LIBS BRIEF_DOCS "Global list of test libs" FULL_DOCS "Global list of test libs")


    #
    # find & setup Qt
    #
    set(CMAKE_AUTOMOC ON)
    find_package(Qt5 5.2 REQUIRED COMPONENTS Widgets SerialPort REQUIRED)

endif()
