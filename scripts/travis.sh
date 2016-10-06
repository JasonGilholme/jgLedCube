
if [[ "$TRAVIS_BUILD_TYPE" = "TESTS" ]]; then
    ./scripts/install_desktop_deps.sh
    socat -d -d pty,raw,echo=0,link=/tmp/ttyOUT pty,raw,echo=0,link=/tmp/ttyIN &  # VIRTUAL SERIAL
    mkdir build && cd build
    cmake -DTEST_SERIAL_OUT=/tmp/ttyOUT -DTEST_SERIAL_IN=/tmp/ttyIN ..
    make
    jgLedCube/c_tests;

elif [[ "$TRAVIS_BUILD_TYPE" = "ARDUINO_DEBUG" ]]; then
    ./scripts/install_embedded_deps.sh
    mkdir build && cd build
    cmake -DBUILD_EMBEDDED=TRUE -DTARGET_HARDWARE=ARDUINO -DARDUINO_DEFAULT_BOARD=uno -DHARDWARE_PROGRAM=DEBUG ..;
    make

fi;
