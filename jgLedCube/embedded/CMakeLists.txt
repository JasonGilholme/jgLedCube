
# COMPILE THE ANIM LIBS
add_subdirectory(anim)


if ( ${BUILD_EMBEDDED} )
    if ( TARGET_HARDWARE STREQUAL ARDUINO )

        generate_arduino_library(jgLedCubeCore
                BOARD ${ARDUINO_DEFAULT_BOARD}
                SRCS  core.cpp)

#        generate_arduino_library(jgLedCubeSerialEmbedded
#                BOARD ${ARDUINO_DEFAULT_BOARD}
#                SRCS  serial_arduino.cpp)

        add_subdirectory( arduino )

    elseif ( TARGET_HARDWARE STREQUAL STM32 )

        add_library(jgLedCubeCore core.cpp)
        STM32_SET_TARGET_PROPERTIES(jgLedCubeCore)
        STM32_ADD_HEX_BIN_TARGETS(jgLedCubeCore)

        #    add_library(jgLedCubeSerial serial.cpp serial_stm32.cpp)
        #    STM32_SET_TARGET_PROPERTIES(jgLedCubeSerialEmbedded)
        #    STM32_ADD_HEX_BIN_TARGETS(jgLedCubeSerialEmbedded)

        add_subdirectory( stm32 )

    endif()
else()

    # BUILD AND TEST THE LIBS
    add_library(jgLedCubeCore core.cpp)
    add_library(jgLedCubeSerialEmbedded serial.cpp)
    target_link_libraries(jgLedCubeSerialEmbedded jgLedCubeSerial)

    add_subdirectory( tests )
endif()
