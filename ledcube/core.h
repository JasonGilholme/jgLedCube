/// Data module for the LedCube.  Handles how data is set in the main array that is used for the cube.


#ifndef LED_CUBE_X_DIMENSION
#define LED_CUBE_X_DIMENSION 4
#endif
#ifndef LED_CUBE_Y_DIMENSION
#define LED_CUBE_Y_DIMENSION 4
#endif
#ifndef LED_CUBE_Z_DIMENSION
#define LED_CUBE_Z_DIMENSION 4
#endif
#ifndef LED_CUBE_N_CHANNELS
#define LED_CUBE_N_CHANNELS 3
#endif

#ifndef HELLOWORLD_DATA_H
#define HELLOWORLD_DATA_H

#include <iostream>
#include <math.h>

namespace jgLedCube{

    // CUBE CONFIGURATION
    static const uint8_t xDimension = LED_CUBE_X_DIMENSION;
    static const uint8_t yDimension = LED_CUBE_Y_DIMENSION;
    static const uint8_t zDimension = LED_CUBE_Z_DIMENSION;
    static const uint8_t nChannels = LED_CUBE_N_CHANNELS;

    // VARS FOR INTERNAL WORKINGS
    static const uint8_t xyDimension = xDimension * yDimension;
    static const uint8_t xyzDimension = xyDimension * zDimension;
    static const uint8_t modulationBits = 4;
    static const uint8_t maxIntensity = 15;
    static const uint8_t nArrayBytes = ceil(xyzDimension / 8.0) * nChannels * modulationBits;

    // THE MAIN DATA ARRAY
    static uint8_t dataArray[nArrayBytes] = {};

    // KEY FUNCTIONS FOR SETTING DATA ON THE CUBE
    void setLed(uint8_t x, uint8_t y, uint8_t z, uint8_t value, uint8_t channel);
    void setLedFloat(float x, float y, float z, uint8_t value, uint8_t channel);
    void clear();

    // GET & SET BITS IN A BYTE
    void setBit(uint8_t &b, const uint8_t &n, const uint8_t &v);
    uint8_t getBit(uint8_t b, uint8_t n);

    // DEBUG PRINTS
    void printConfig();
    void printData();

}

#endif //HELLOWORLD_DATA_H
