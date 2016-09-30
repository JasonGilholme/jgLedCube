cmake_minimum_required(VERSION 3.6)

if (NOT DEFINED TARGET_HARDWARE)
    message( STATUS "TARGET_HARDWARE is not set! Only tests will be built.  Set to ARDUINO or STM32 to build deployable targets..." )
endif()

include(cmake/SetupProject.cmake)
project(jgLedCube)


# ======================================================= #
# ENSURE WE HAVE ALL THE INPUT VARS WE NEED FROM THE USER #
# ======================================================= #
if ( TARGET_HARDWARE STREQUAL ARDUINO )
    if ( NOT DEFINED ARDUINO_DEFAULT_BOARD )
        message( FATAL_ERROR "ARDUINO_DEFAULT_BOARD variable not defined!" )
    endif()
endif()

if ( TARGET_HARDWARE STREQUAL STM32 )
    if ( NOT DEFINED STM32_CHIP )
        message( FATAL_ERROR "STM32_CHIP variable not defined!" )
    endif()
endif()


# ======================================================= #
#      SET SOME DEFAULT CUBE SPECS IF NOT SPECIFIED       #
# ======================================================= #
if (NOT CUBE_NAME)
    set( CUBE_NAME "MyLedCube" )
endif()

if (NOT CUBE_SIZE_X)
    set( CUBE_SIZE_X 4 )
endif()

if (NOT CUBE_SIZE_Y)
    set( CUBE_SIZE_Y 4 )
endif()

if (NOT CUBE_SIZE_Z)
    set( CUBE_SIZE_Z 4 )
endif()

if (NOT CUBE_N_COLOURS)
    set( CUBE_N_COLOURS 3 )
endif()


message( STATUS "BUILD_TESTS: ${BUILD_TESTS}")
message( STATUS "BUILD_ARDUINO: ${BUILD_ARDUINO}")
message( STATUS "BUILD_STM32: ${BUILD_STM32}")
message( STATUS "CUBE_SIZE_X: ${CUBE_SIZE_X}")
message( STATUS "CUBE_SIZE_Y: ${CUBE_SIZE_Y}")
message( STATUS "CUBE_SIZE_Z: ${CUBE_SIZE_Z}")
message( STATUS "CUBE_N_COLOURS: ${CUBE_N_COLOURS}")

# ======================================================= #
#     INTERNAL PROJECT SETUP - VARS, TOOLCHAINS, ETC.     #
# ======================================================= #

# START TO ADD ALL THE COMPONENTS OF THE PROJECT
add_subdirectory(jgLedCube)
