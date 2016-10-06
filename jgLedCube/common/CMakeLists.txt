
if ( ${BUILD_EMBEDDED} )
    if ( TARGET_HARDWARE STREQUAL ARDUINO )

        generate_arduino_library(jgLedCubeSerial
                BOARD ${ARDUINO_DEFAULT_BOARD}
                SRCS  serial.cpp)

    elseif ( TARGET_HARDWARE STREQUAL STM32 )

        add_library(jgLedCubeSerial serial.cpp)
        STM32_SET_TARGET_PROPERTIES(jgLedCubeSerial)
        STM32_ADD_HEX_BIN_TARGETS(jgLedCubeSerial)

    endif()
else()

    # BUILD AND TEST THE LIBS
    add_library(jgLedCubeSerial serial.cpp serial_desktop.cpp)
    target_link_libraries(jgLedCubeSerial boost_system)

    add_subdirectory( tests )

endif()
