
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

    add_library( jgLedCubeSerial serial.cpp )
    target_link_libraries( jgLedCubeSerial )

    add_library( jgLedCubeSerialDesktop serial_desktop.cpp )
    target_link_libraries( jgLedCubeSerialDesktop jgLedCubeSerial ${Boost_SYSTEM_LIBRARY_RELEASE} )

    install( TARGETS jgLedCubeSerial jgLedCubeSerialDesktop ARCHIVE DESTINATION lib)

    add_subdirectory( tests )

endif()
