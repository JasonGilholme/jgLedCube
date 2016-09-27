/// Data module for the LedCube.  Handles how data is set in the main array that is used for the cube.


#ifndef HELLOWORLD_DATA_H
#define HELLOWORLD_DATA_H

#include <iostream>
#include <math.h>

#define LED_CUBE_X_DIMENSION 4
#define LED_CUBE_Y_DIMENSION 4
#define LED_CUBE_Z_DIMENSION 4
#define LED_CUBE_N_CHANNELS 3

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
    static const uint8_t nArrayBytes = ceil(xyzDimension / 8.0);

    // THE MAIN DATA ARRAY
    static volatile uint8_t dataArray[nChannels * modulationBits * nArrayBytes] = {};

    // KEY FUNCTIONS FOR SETTING DATA ON THE CUBE
    void set_led(uint8_t x, uint8_t y, uint8_t z, uint8_t value,uint8_t channel);
    void set_float(float x, float y, float z, uint8_t value, uint8_t channel);

    void setBit(char &b, const char &n, const char &v);
    char getBit(char b, char n);

    void get_led(uint8_t x, uint8_t y, uint8_t z);

    // DEBUG PRINTS
    void print_config();
    void print_data();

}

#endif //HELLOWORLD_DATA_H
