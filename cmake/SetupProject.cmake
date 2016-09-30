
include_directories(${CMAKE_SOURCE_DIR})

set( CUBE_VERSION 0 )

if ( TARGET_HARDWARE STREQUAL ARDUINO )

    add_definitions( -DARDUINO_BUILD=1 )
    set( BUILD_TESTS OFF )
    set( BUILD_ARDUINO ON )
    set( BUILD_STM32 OFF )

    # USE THE ARDUINO CMAKE SETUP FROM queezythegreat - https://github.com/queezythegreat/arduino-cmake
    set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino_toolchain/ArduinoToolchain.cmake )

elseif ( TARGET_HARDWARE STREQUAL STM32 )

    add_definitions( -DSTM32_BUILD=1 )
    set( BUILD_TESTS OFF )
    set( BUILD_ARDUINO OFF )
    set( BUILD_STM32 ON )

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
    # FORCE CUBE SPECS FOR TESTING PURPOSES
    set( CUBE_NAME "TestLedCube" )
    set( CUBE_SIZE_X 4)
    set( CUBE_SIZE_Y 4)
    set( CUBE_SIZE_Z 4)
    set( CUBE_N_COLOURS 3)

    add_definitions( -DPC_BUILD=1 )
    set( BUILD_TESTS ON )
    set( BUILD_ARDUINO OFF )
    set( BUILD_STM32 OFF )

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    # ADD GOOGLE TEST DIRECTORIES
    # TODO: FindGoogletest.cmake??
    include_directories( $ENV{REZ_GOOGLETEST_ROOT}/include )
    link_directories( $ENV{REZ_GOOGLETEST_ROOT}/lib )

endif()
