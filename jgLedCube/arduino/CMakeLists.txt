
generate_arduino_firmware(ARDUINO_debug
        SKETCH debug.cpp
        #HDRS
        LIBS jgLedCubeCore #jgLedCubeSerial
        #PORT
        #SERIAL
        PROGRAMMER usbasp
        #AFLAGS
        #NO_AUTOLIBS
        )
