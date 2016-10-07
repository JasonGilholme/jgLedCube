
include_directories(${CMAKE_SOURCE_DIR})


if ( ${BUILD_EMBEDDED} )

    add_definitions(
            -DTARGET_HARDWARE=${TARGET_HARDWARE}
            -DBUILD_EMBEDDED=${BUILD_EMBEDDED}
    )

    if (NOT DEFINED HARDWARE_PROGRAM)
        set( HARDWARE_PROGRAM DEBUG)
    endif()

    if ( TARGET_HARDWARE STREQUAL ARDUINO )

        # USE THE ARDUINO CMAKE SETUP FROM queezythegreat - https://github.com/queezythegreat/arduino-cmake
        set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino_toolchain/ArduinoToolchain.cmake )

    elseif ( TARGET_HARDWARE STREQUAL STM32 )

        # USE THE STM32 CMAKE SETUP FROM ObKo - https://github.com/ObKo/stm32-cmake
        set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/stm32_toolchain/gcc_stm32.cmake )
        set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/stm32_toolchain )

        ENABLE_LANGUAGE(ASM)

        FIND_PACKAGE(CMSIS REQUIRED)
        INCLUDE_DIRECTORIES(${CMSIS_INCLUDE_DIRS})

        FIND_PACKAGE(STM32HAL REQUIRED)
        INCLUDE_DIRECTORIES(${STM32HAL_INCLUDE_DIR})

        SET(STM32_LINKER_SCRIPT ${CMSIS_LINKER_SCRIPT})

    endif()

else()

    # FORCE CUBE SPECS FOR TESTING PURPOSES
    set( CUBE_NAME "TestLedCube" )
    set( CUBE_SIZE_X 4)
    set( CUBE_SIZE_Y 4)
    set( CUBE_SIZE_Z 4)
    set( CUBE_N_COLOURS 3)

    if  ( DEFINED TEST_SERIAL_OUT AND DEFINED TEST_SERIAL_IN )
        add_definitions(
                -DLED_CUBE_IN_SERIAL_PORT="${TEST_SERIAL_IN}"
                -DLED_CUBE_OUT_SERIAL_PORT="${TEST_SERIAL_OUT}"
        )
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    # ADD GOOGLE TEST DIRECTORIES
    # TODO: FindGoogletest.cmake??
    include_directories( $ENV{REZ_GOOGLETEST_ROOT}/include )
    link_directories( $ENV{REZ_GOOGLETEST_ROOT}/lib )

    include_directories( $ENV{REZ_PYTHON_ROOT}/include/python2.7 )
    link_directories( $ENV{REZ_PYTHON_ROOT}/lib )

endif()


# ======================================================= #
#      SET SOME DEFAULT CUBE SPECS IF NOT SPECIFIED       #
# ======================================================= #

# TODO: Setup some sort of switch for embedded things that aren't actually a cube. e.g. controllers, interpreters etc.
set( CUBE_VERSION 0 )

if (NOT CUBE_NAME)
    set( CUBE_NAME "MyLedCube" )
endif()

if (NOT CUBE_UID)
    set( CUBE_UID 54321 )
endif()

if (NOT CUBE_SIZE_X)
    set( CUBE_SIZE_X 4 )
endif()

if (NOT CUBE_SIZE_Y)
    set( CUBE_SIZE_Y 4 )
endif()

if (NOT CUBE_SIZE_Z)
    set( CUBE_SIZE_Z 4 )
endif()

if (NOT CUBE_N_COLOURS)
    set( CUBE_N_COLOURS 3 )
endif()


message( STATUS "BUILD_TESTS: ${BUILD_TESTS}")
message( STATUS "BUILD_ARDUINO: ${BUILD_ARDUINO}")
message( STATUS "BUILD_STM32: ${BUILD_STM32}")
message( STATUS "CUBE_SIZE_X: ${CUBE_SIZE_X}")
message( STATUS "CUBE_SIZE_Y: ${CUBE_SIZE_Y}")
message( STATUS "CUBE_SIZE_Z: ${CUBE_SIZE_Z}")
message( STATUS "CUBE_N_COLOURS: ${CUBE_N_COLOURS}")


# DEFINE ALL THE ARGS FOR THE PRE PROCESSOR
add_definitions(
        -DLED_CUBE_X_DIMENSION=${CUBE_SIZE_X}
        -DLED_CUBE_Y_DIMENSION=${CUBE_SIZE_Y}
        -DLED_CUBE_Z_DIMENSION=${CUBE_SIZE_Z}
        -DLED_CUBE_N_CHANNELS=${CUBE_N_COLOURS}
        -DLED_CUBE_NAME="${CUBE_NAME}"
        -DLED_CUBE_UID=${CUBE_UID}
        -DLED_CUBE_VERSION=${CUBE_VERSION}
        -DTEST_SERIAL_PORT=${TEST_SERIAL_PORT}
)
