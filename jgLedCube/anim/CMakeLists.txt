
if ( ${BUILD_TESTS} )
    add_library(jgLedCubeAnimDebug debug.cpp)
    add_library(jgLedCubeAnimSweep sweep.cpp)
endif()

if ( ${BUILD_ARDUINO} )
    generate_arduino_library(jgLedCubeAnimDebug SRCS debug.cpp)
    generate_arduino_library(jgLedCubeAnimSweep SRCS sweep.cpp)
endif()

#if ( ${BUILD_STM32} )
#    add_library(jgLedCubeCore core.cpp)
#    STM32_SET_TARGET_PROPERTIES(jgLedCubeCore)
#    STM32_ADD_HEX_BIN_TARGETS(jgLedCubeCore)
#endif()