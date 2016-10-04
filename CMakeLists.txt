cmake_minimum_required(VERSION 3.0)

if (DEFINED TESTING)
    add_definitions(-DTESTING=${TESTING})
    if (NOT DEFINED TEST_SERIAL_PORT)
        message( WARNING "TEST_SERIAL_PORT argument not provided! No serial port tests wil run..." )
    else()
        add_definitions(-DTEST_SERIAL_PORT=${TEST_SERIAL_PORT})
    endif()

else()
    if (DEFINED BUILD_EMBEDDED)
        if (NOT DEFINED TARGET_HARDWARE)
            message( FATAL_ERROR "TARGET_HARDWARE argument not provided..." )
        endif()

        # CHECK FOR HARDWARE SPECIFIC ARGS
        if ( TARGET_HARDWARE STREQUAL ARDUINO )
            if ( NOT DEFINED ARDUINO_DEFAULT_BOARD )
                message( FATAL_ERROR "ARDUINO_DEFAULT_BOARD variable not defined!" )
            endif()
        elseif( TARGET_HARDWARE STREQUAL STM32 )
            if ( NOT DEFINED STM32_CHIP )
                message( FATAL_ERROR "STM32_CHIP variable not defined!" )
            endif()
        else()
            message( FATAL_ERROR "Invalid value for TARGET_HARDWARE!" )
        endif()

    endif()
endif()

include(cmake/SetupProject.cmake)

project(jgLedCube)


# START TO ADD ALL THE COMPONENTS OF THE PROJECT
add_subdirectory(jgLedCube)
