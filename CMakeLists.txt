cmake_minimum_required(VERSION 2.8)

set(CMAKE_VERBOSE_MAKEFILE ON)

include(cmake/SetupProject.cmake)
project(jgLedCube)

# cmake options here?
set( CUBE_NAME "MyLedCube" )
set( CUBE_VERSION 0 )
set( CUBE_SIZE_X 4)
set( CUBE_SIZE_Y 4)
set( CUBE_SIZE_Z 4)
set( CUBE_N_COLOURS 3)

add_subdirectory(jgLedCube)

if ( ${BUILD_TESTS} )
    add_subdirectory(jgLedCube/pc)
endif()

if ( ${BUILD_ARDUINO} )
    add_subdirectory( jgLedCube/arduino )
endif()

if ( ${BUILD_STM32} )
    add_subdirectory( jgLedCube/stm32 )
endif()
