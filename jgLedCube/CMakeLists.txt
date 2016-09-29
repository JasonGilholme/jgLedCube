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


add_library(jgLedCubeCore core.cpp)
target_compile_definitions(jgLedCubeCore
        PUBLIC
        LED_CUBE_X_DIMENSION=${CUBE_X}
        LED_CUBE_Y_DIMENSION=${CUBE_Y}
        LED_CUBE_Z_DIMENSION=${CUBE_Z}
        LED_CUBE_N_CHANNELS=${N_CHANNELS}
        )


message( STATUS "BUILD_TESTS: ${BUILD_TESTS}")
message( STATUS "BUILD_ARDUINO: ${BUILD_ARDUINO}")
message( STATUS "BUILD_STM32: ${BUILD_STM32}")
message( STATUS "CUBE_X: ${CUBE_X}")
message( STATUS "CUBE_Y: ${CUBE_Y}")
message( STATUS "CUBE_Z: ${CUBE_Z}")
message( STATUS "N_CHANNELS: ${N_CHANNELS}")


#if ( ${BUILD_TESTS} )
#    add_library(jgLedCubeSerial serial.cpp serial_test.cpp)
#endif()
#
#if ( ${BUILD_ARDUINO} )
#    add_library(jgLedCubeSerial serial.cpp serial_arduino.cpp)
#endif()
#
#if ( ${BUILD_STM32} )
#    add_library(jgLedCubeSerial serial.cpp serial_stm32.cpp)
#endif()

