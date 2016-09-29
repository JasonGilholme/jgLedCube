cmake_minimum_required(VERSION 3.6)
include(cmake/SetupProject.cmake)
project(jgLedCube)

add_subdirectory(jgLedCube)

if ( ${BUILD_TESTS} )
    add_subdirectory( jgLedCube/test )
endif()

if ( ${BUILD_ARDUINO} )
    add_subdirectory( jgLedCube/arduino )
endif()

if ( ${BUILD_STM32} )
    add_subdirectory( jgLedCube/stm32 )
endif()
