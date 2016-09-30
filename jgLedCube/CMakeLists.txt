
add_library(jgLedCubeCore core.cpp)
target_compile_definitions(jgLedCubeCore
        PUBLIC
        LED_CUBE_X_DIMENSION=${CUBE_SIZE_X}
        LED_CUBE_Y_DIMENSION=${CUBE_SIZE_Y}
        LED_CUBE_Z_DIMENSION=${CUBE_SIZE_Z}
        LED_CUBE_N_CHANNELS=${CUBE_N_COLOURS}
        LED_CUBE_NAME="${CUBE_NAME}"
        LED_CUBE_UID=0  # TODO: Generate unique number per build
        LED_CUBE_VERSION=${CUBE_VERSION}
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

