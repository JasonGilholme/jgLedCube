add_library(jgLedCubeSerial serial.cpp serial_desktop.cpp)  # TODO: Use serial_${hardwaretype} at some point
target_link_libraries(jgLedCubeSerial boost_system)

if ( NOT DEFINED BUILD_EMBEDDED )
    add_subdirectory(tests)
endif()
