if (CUBE_TARGET_PLATFORM STREQUAL desktop)

    add_library( jgLedCubeSerial STATIC serial.cpp )
    target_link_libraries( jgLedCubeSerial )
    install( TARGETS jgLedCubeSerial ARCHIVE DESTINATION lib)

    add_subdirectory( tests )
    add_subdirectory( desktop )

elseif ( CUBE_TARGET_PLATFORM STREQUAL arduino )

    generate_arduino_library(jgLedCubeSerial
            BOARD ${ARDUINO_DEFAULT_BOARD}
            SRCS  serial.cpp)

    add_subdirectory( embedded )

elseif ( TARGET_HARDWARE STREQUAL STM32 )

    add_library(jgLedCubeSerial serial.cpp)
    STM32_SET_TARGET_PROPERTIES(jgLedCubeSerial)
    STM32_ADD_HEX_BIN_TARGETS(jgLedCubeSerial)

    add_subdirectory( embedded )

endif()
