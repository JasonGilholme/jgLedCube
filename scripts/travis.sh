
if [[ "$TARGET_PLATFORM" = "desktop" ]]; then
    ./scripts/install_desktop_deps.sh
    socat -d -d pty,raw,echo=0,link=/tmp/ttyOUT pty,raw,echo=0,link=/tmp/ttyIN &  # VIRTUAL SERIAL
    mkdir build && cd build
    cmake -DCUBE_TARGET_PLATFORM=desktop -DTEST_SERIAL_OUT=/tmp/ttyOUT -DTEST_SERIAL_IN=/tmp/ttyIN -DCMAKE_INSTALL_PREFIX=./install ..
    make install
    # install/bin/gtests
    # python install/lib/python/test.py;

elif [[ "$TARGET_PLATFORM" = "arduino" ]]; then
    ./scripts/install_embedded_deps.sh
    mkdir build && cd build
    cmake -DCUBE_TARGET_PLATFORM=arduino ..;
    make

fi;
