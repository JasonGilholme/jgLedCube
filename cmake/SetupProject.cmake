
include_directories(${CMAKE_SOURCE_DIR})

if ( TARGET_HARDWARE STREQUAL ARDUINO )

    add_definitions( -DARDUINO_BUILD=1 )
    set( BUILD_TESTS OFF )
    set( BUILD_ARDUINO ON )
    set( BUILD_STM32 OFF )

    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino_toolchain/ArduinoToolchain.cmake )
    set( ARDUINO_DEFAULT_BOARD atmega328 )      # Default Board ID, when not specified
    set( ARDUINO_DEFAULT_PORT /dev/ttyACM0 )    # Default Port, when not specified

elseif ( TARGET_HARDWARE STREQUAL STM32 )

    add_definitions( -DSTM32_BUILD=1 )
    set( BUILD_TESTS OFF )
    set( BUILD_ARDUINO OFF )
    set( BUILD_STM32 ON )

else()

    add_definitions( -DPC_BUILD=1 )
    set( BUILD_TESTS ON )
    set( BUILD_ARDUINO OFF )
    set( BUILD_STM32 OFF )

endif()


# =========================================================================== #
# SETS DEFAULT BUILD VALUES FOR UNSUPPLIED VARIABLES
# =========================================================================== #

if (NOT DEFINED CUBE_X)
    set(CUBE_X 4)
endif()
if (NOT DEFINED CUBE_Y)
    set(CUBE_Y 4)
endif()
if (NOT DEFINED CUBE_Z)
    set(CUBE_Z 4)
endif()

if (NOT DEFINED N_CHANNELS)
    set(N_CHANNELS 1)
endif()

add_definitions( -DLED_CUBE_X_DIMENSION=${CUBE_X} )
add_definitions( -DLED_CUBE_Y_DIMENSION=${CUBE_Y} )
add_definitions( -DLED_CUBE_Z_DIMENSION=${CUBE_Z} )
add_definitions( -DLED_CUBE_N_CHANNELS=${N_CHANNELS} )

message( STATUS "BUILD_TESTS: ${BUILD_TESTS}")
message( STATUS "BUILD_ARDUINO: ${BUILD_ARDUINO}")
message( STATUS "BUILD_STM32: ${BUILD_STM32}")
message( STATUS "CUBE_X: ${CUBE_X}")
message( STATUS "CUBE_Y: ${CUBE_Y}")
message( STATUS "CUBE_Z: ${CUBE_Z}")
message( STATUS "N_CHANNELS: ${N_CHANNELS}")


