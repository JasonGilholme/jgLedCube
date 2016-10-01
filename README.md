[![Build Status](https://travis-ci.org/JasonGilholme/jgLedCube-embedded.png)](https://travis-ci.org/JasonGilholme/jgLedCube-embedded)

## jgLedCube-embedded

Check out the .travis.yml file for dependencies.

### Configuration CMake options

    -DCUBE_NAME=MyLedCube
    -DCUBE_SIZE_X=4
    -DCUBE_SIZE_Y=4
    -DCUBE_SIZE_Z=4
    -DCUBE_N_COLOURS=3
    -DPROGRAM_TO_BUILD=ANIMS


### Arduino Specific Notes

    -DTARGET_HARDWARE=ARDUINO
    -DARDUINO_DEFAULT_BOARD=uno
    -DARDUINO_DEFAULT_PORT=/dev/ttyUSB0
    -DARDUINO_DEFAULT_PROGRAMMER=usbasp

    
### STM32 Specific Notes

    -DTARGET_HARDWARE=STM32
    -DSTM32_CHIP=STM32F407VG
    -DSTM32Cube_DIR=/home/jase/STM32Cube/Repository/STM32Cube_FW_F4_V1.13.0

I needed to get newlib from here:  http://http.us.debian.org/debian/pool/main/libs/libstdc++-arm-none-eabi/libstdc++-arm-none-eabi-newlib_4.9.3+svn227297-1+8_all.deb
The default std lib from the Ubuntu-14.04 LTS package manager was broken.

