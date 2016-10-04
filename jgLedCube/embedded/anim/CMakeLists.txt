
if ( ${BUILD_EMBEDDED} )

    if ( TARGET_HARDWARE STREQUAL ARDUINO )

        generate_arduino_library(jgLedCubeAnimDebug SRCS debug.cpp)
        generate_arduino_library(jgLedCubeAnimSweep SRCS sweep.cpp)
        generate_arduino_library(jgLedCubeAnimFade SRCS fade.cpp)

    elseif ( TARGET_HARDWARE STREQUAL STM32 )

        add_library(jgLedCubeAnimDebug debug.cpp)
        STM32_SET_TARGET_PROPERTIES(jgLedCubeAnimDebug)
        STM32_ADD_HEX_BIN_TARGETS(jgLedCubeAnimDebug)

        add_library(jgLedCubeAnimSweep sweep.cpp)
        STM32_SET_TARGET_PROPERTIES(jgLedCubeAnimSweep)
        STM32_ADD_HEX_BIN_TARGETS(jgLedCubeAnimSweep)

        add_library(jgLedCubeAnimFade fade.cpp)
        STM32_SET_TARGET_PROPERTIES(jgLedCubeAnimFade)
        STM32_ADD_HEX_BIN_TARGETS(jgLedCubeAnimFade)

    endif()




else()
    add_library(jgLedCubeAnimDebug debug.cpp)
    add_library(jgLedCubeAnimSweep sweep.cpp)
    add_library(jgLedCubeAnimFade fade.cpp)
endif()
