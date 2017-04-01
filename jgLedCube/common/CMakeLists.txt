if (CUBE_TARGET_PLATFORM STREQUAL desktop)

    add_library( common_serial STATIC serial.cpp )
    target_link_libraries( common_serial )
    install( TARGETS common_serial ARCHIVE DESTINATION lib)

    add_subdirectory( tests )

elseif ( CUBE_TARGET_PLATFORM STREQUAL arduino )

    generate_arduino_library(common_serial
            BOARD ${ARDUINO_DEFAULT_BOARD}
            SRCS  serial.cpp)

elseif ( TARGET_HARDWARE STREQUAL STM32 )

    add_library(common_serial serial.cpp)
    STM32_SET_TARGET_PROPERTIES(common_serial)
    STM32_ADD_HEX_BIN_TARGETS(common_serial)

endif()
