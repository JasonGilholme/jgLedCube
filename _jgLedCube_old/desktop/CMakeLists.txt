
add_library(jgLedCubeSerialDesktop serial.cpp)

if (${TESTING})
    add_subdirectory(tests)
endif()