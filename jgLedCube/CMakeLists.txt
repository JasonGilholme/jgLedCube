
# DEFINE ALL THE ARGS FOR THE PRE PROCESSOR
add_definitions(
        -DLED_CUBE_X_DIMENSION=${CUBE_SIZE_X}
        -DLED_CUBE_Y_DIMENSION=${CUBE_SIZE_Y}
        -DLED_CUBE_Z_DIMENSION=${CUBE_SIZE_Z}
        -DLED_CUBE_N_CHANNELS=${CUBE_N_COLOURS}
        -DLED_CUBE_NAME="${CUBE_NAME}"
        -DLED_CUBE_UID=0  # TODO: Generate unique number per build
        -DLED_CUBE_VERSION=${CUBE_VERSION}
)

# COMPILE THE ANIM LIBS
add_subdirectory(anim)


if ( ${BUILD_TESTS} )
    add_library(jgLedCubeCore core.cpp)
#    add_library(jgLedCubeSerial serial.cpp serial_test.cpp)

    add_subdirectory( pc )
endif()


if ( ${BUILD_ARDUINO} )
    generate_arduino_library(jgLedCubeCore
            BOARD ${ARDUINO_DEFAULT_BOARD}
            SRCS  core.cpp)
#    generate_arduino_library(jgLedCubeSerial
#            BOARD ${ARDUINO_DEFAULT_BOARD}
#            SRCS  serial.cpp serial_arduino.cpp)

    add_subdirectory( arduino )
endif()


if ( ${BUILD_STM32} )
    add_library(jgLedCubeCore core.cpp)
    STM32_SET_TARGET_PROPERTIES(jgLedCubeCore)
    STM32_ADD_HEX_BIN_TARGETS(jgLedCubeCore)

#    add_library(jgLedCubeSerial serial.cpp serial_stm32.cpp)
#    STM32_SET_TARGET_PROPERTIES(jgLedCubeSerial)
#    STM32_ADD_HEX_BIN_TARGETS(jgLedCubeSerial)

    add_subdirectory( stm32 )
endif()
