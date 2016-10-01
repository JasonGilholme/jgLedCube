
if ( PROGRAM_TO_BUILD STREQUAL ANIMS )
    generate_arduino_firmware(ARDUINO_anims
            SKETCH anims.cpp
            LIBS
            jgLedCubeCore
            jgLedCubeAnimDebug
            )
elseif()

else()
    generate_arduino_firmware(ARDUINO_debug
            SKETCH debug.cpp
            LIBS
            jgLedCubeCore
            jgLedCubeAnimDebug
            )
endif()
