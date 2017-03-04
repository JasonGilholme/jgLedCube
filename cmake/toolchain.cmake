set(CUBE_TARGET_PLATFORM "desktop" CACHE STRING "The platform that you're compiling for.")

if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    #  -- nothing --

elseif (${CUBE_TARGET_PLATFORM} STREQUAL android)
    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/android_toolchain/android.toolchain.cmake )

elseif (${CUBE_TARGET_PLATFORM} STREQUAL arduino)
    # USE THE ARDUINO CMAKE SETUP FROM queezythegreat - https://github.com/queezythegreat/arduino-cmake
    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino_toolchain/ArduinoToolchain.cmake )

elseif (${CUBE_TARGET_PLATFORM} STREQUAL stm)
    # USE THE STM32 CMAKE SETUP FROM ObKo - https://github.com/ObKo/stm32-cmake
    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/stm32_toolchain/gcc_stm32.cmake )
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/stm32_toolchain )

    ENABLE_LANGUAGE(ASM)

    FIND_PACKAGE(CMSIS REQUIRED)
    INCLUDE_DIRECTORIES(${CMSIS_INCLUDE_DIRS})

    FIND_PACKAGE(STM32HAL REQUIRED)
    INCLUDE_DIRECTORIES(${STM32HAL_INCLUDE_DIR})

    SET(STM32_LINKER_SCRIPT ${CMSIS_LINKER_SCRIPT})

else()
    message(FATAL_ERROR "Invalid CUBE_TARGET_PLATFORM! Please provide either: 'desktop', 'android', 'arduino' or 'stm32'. e.g.  cmake -DCUBE_TARGET_PLATFORM=pc.")
endif()
