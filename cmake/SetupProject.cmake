
include_directories(${CMAKE_SOURCE_DIR})

if ( TARGET_HARDWARE STREQUAL ARDUINO )

    add_definitions( -DARDUINO_BUILD=1 )
    set( BUILD_TESTS OFF )
    set( BUILD_ARDUINO ON )
    set( BUILD_STM32 OFF )

    # USE THE ARDUINO CMAKE SETUP FROM queezythegreat - https://github.com/queezythegreat/arduino-cmake
    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino_toolchain/ArduinoToolchain.cmake )

    if ( NOT DEFINED ARDUINO_DEFAULT_BOARD )
        set( ARDUINO_DEFAULT_BOARD uno )
    endif()
    if ( NOT DEFINED ARDUINO_DEFAULT_BOARD )
        set( ARDUINO_DEFAULT_PORT /dev/ttyACM0 )
    endif()

elseif ( TARGET_HARDWARE STREQUAL STM32 )

    add_definitions( -DSTM32_BUILD=1 )
    set( BUILD_TESTS OFF )
    set( BUILD_ARDUINO OFF )
    set( BUILD_STM32 ON )

    # USE THE STM32 CMAKE SETUP FROM ObKo - https://github.com/ObKo/stm32-cmake
    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/stm32_toolchain/gcc_stm32.cmake )
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/stm32_toolchain )

    if ( NOT DEFINED STM32_CHIP )
        message( FATAL_ERROR "STM32_CHIP variable not defined!" )
        set ( STM32_CHIP STM32F407VG )
    endif()

    ENABLE_LANGUAGE(ASM)

    FIND_PACKAGE(CMSIS REQUIRED)
    FIND_PACKAGE(STM32HAL COMPONENTS gpio tim REQUIRED)

    INCLUDE_DIRECTORIES(
            ${CMSIS_INCLUDE_DIRS}
            ${STM32HAL_INCLUDE_DIR}
    )

    SET(STM32_LINKER_SCRIPT ${CMSIS_LINKER_SCRIPT})

else()

    # FORCE CUBE SPECS FOR TESTING PURPOSES
    set(CUBE_X 2)
    set(CUBE_Y 2)
    set(CUBE_Z 2)
    set(N_CHANNELS 3)

    add_definitions( -DPC_BUILD=1 )
    set( BUILD_TESTS ON )
    set( BUILD_ARDUINO OFF )
    set( BUILD_STM32 OFF )

endif()


