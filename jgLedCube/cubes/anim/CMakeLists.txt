if ( CUBE_TARGET_PLATFORM STREQUAL arduino )
    generate_arduino_library(anim_debug SRCS debug.cpp)
    generate_arduino_library(anim_sweep SRCS sweep.cpp)
    generate_arduino_library(anim_fade SRCS fade.cpp)

elseif ( CUBE_TARGET_PLATFORM STREQUAL STM32 )
    add_library(jgLedCubeAnimDebug debug.cpp)
    STM32_SET_TARGET_PROPERTIES(anim_debug)
    STM32_ADD_HEX_BIN_TARGETS(anim_debug)

    add_library(jgLedCubeAnimSweep sweep.cpp)
    STM32_SET_TARGET_PROPERTIES(anim_sweep)
    STM32_ADD_HEX_BIN_TARGETS(anim_sweep)

    add_library(jgLedCubeAnimFade fade.cpp)
    STM32_SET_TARGET_PROPERTIES(anim_fade)
    STM32_ADD_HEX_BIN_TARGETS(anim_fade)

else()
    add_library(anim_debug debug.cpp)
    add_library(anim_sweep sweep.cpp)
    add_library(anim_fade fade.cpp)
    install( TARGETS anim_debug anim_sweep anim_fade ARCHIVE DESTINATION lib )
endif()