# Compile the anim libs
add_subdirectory(anim)

if ( CUBE_TARGET_PLATFORM STREQUAL arduino )
    generate_arduino_library(cube_core
            BOARD ${ARDUINO_DEFAULT_BOARD}
            SRCS  core.cpp)
    add_subdirectory( arduino )

elseif ( CUBE_TARGET_PLATFORM STREQUAL STM32 )
    add_library(cube_core core.cpp)
    STM32_SET_TARGET_PROPERTIES(cube_core)
    STM32_ADD_HEX_BIN_TARGETS(cube_core)

    add_subdirectory( stm32 )

elseif ( CUBE_TARGET_PLATFORM STREQUAL desktop )
    # Build and test the libraries
    add_library(cube_core core.cpp core_desktop.cpp)

    add_library(cube_serial serial.cpp)
    target_link_libraries(cube_serial) # jgLedCubeSerial

    add_subdirectory( tests )
endif()
