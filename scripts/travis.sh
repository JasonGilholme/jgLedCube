
# BASE ON SOME ENV VARS INSTALL THE RIGHT DEPENDENCIES AND RUN THE RIGHT SCRIPT
#
#   TESTS
#   ARDUINO_DEBUG
#   STM32_DEBUG

if [[ "$TRAVIS_BUILD_TYPE" = "TESTS" ]]; then
    ./scripts/install_desktop_deps.sh
    mkdir build && cd build
    cmake -DTEST_SERIAL_OUT=/dev/ttyUSB0 -DTEST_SERIAL_IN=/dev/ttyUSB1 ..
    # TODO:  Use socat here to trigger simulate the serial ports
    make
    jgLedCube/c_tests;

elif [[ "$TRAVIS_BUILD_TYPE" = "ARDUINO_DEBUG" ]]; then
    ./scripts/install_embedded_deps.sh
    mkdir build && cd build
    cmake -DBUILD_EMBEDDED=TRUE -DTARGET_HARDWARE=ARDUINO -DARDUINO_DEFAULT_BOARD=uno -DHARDWARE_PROGRAM=DEBUG ..;
fi;
