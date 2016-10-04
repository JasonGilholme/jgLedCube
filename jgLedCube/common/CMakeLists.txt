add_library(jgLedCubeSerial serial.cpp)

if ( NOT DEFINED BUILD_EMBEDDED )
    add_subdirectory(tests)
endif()
