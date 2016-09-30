/// Core data functions & variables for cube operation.

#ifndef JGLEDCUBE_CORE_H
#define JGLEDCUBE_CORE_H

#define LED_CUBE_XY_DIMENSION           LED_CUBE_X_DIMENSION * LED_CUBE_Y_DIMENSION
#define LED_CUBE_XYZ_DIMENSION          LED_CUBE_XY_DIMENSION * LED_CUBE_Y_DIMENSION
#define LED_CUBE_MODULATION_BITS        4
#define LED_CUBE_MAX_INTENSITY          15
#define LED_CUBE_MODULATION_BLOCK_SIZE  LED_CUBE_XYZ_DIMENSION / 8.0 * LED_CUBE_N_CHANNELS
#define LED_CUBE_DATA_ARRAY_SIZE        LED_CUBE_MODULATION_BLOCK_SIZE * LED_CUBE_MODULATION_BITS

#include <stdint.h>

namespace jgLedCube {
    namespace core {

        static const char* cubeName = LED_CUBE_NAME;
        static const double cubeUid = LED_CUBE_UID;
        static const double cubeVersion = LED_CUBE_VERSION;

        // CUBE CONFIGURATION
        static const uint8_t xDimension = LED_CUBE_X_DIMENSION;
        static const uint8_t yDimension = LED_CUBE_Y_DIMENSION;
        static const uint8_t zDimension = LED_CUBE_Z_DIMENSION;
        static const uint8_t nChannels = LED_CUBE_N_CHANNELS;

        // VARS FOR INTERNAL WORKINGS
        static const uint8_t xyDimension = LED_CUBE_XY_DIMENSION;
        static const uint8_t xyzDimension = LED_CUBE_XYZ_DIMENSION;
        static const uint8_t modulationBits = LED_CUBE_MODULATION_BITS;
        static const uint8_t maxIntensity = LED_CUBE_MAX_INTENSITY;
        static const uint8_t modBlockSize = LED_CUBE_MODULATION_BLOCK_SIZE;
        static const uint8_t dataArraySize = LED_CUBE_DATA_ARRAY_SIZE;

        // THE MAIN DATA ARRAY
        static uint8_t dataArray[dataArraySize] = {};

        // KEY FUNCTIONS FOR SETTING DATA ON THE CUBE
        void setLed(uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b);
        void setLedFloat(float x, float y, float z, uint8_t r, uint8_t g, uint8_t b);
        void clear();

        // GET & SET BITS IN A BYTE
        void setBit(uint8_t &b, const uint8_t &n, const uint8_t &v);
        uint8_t getBit(uint8_t b, uint8_t n);

        // DEBUG PRINTS
        void printConfig();
        void printData();
    }
}

#endif //JGLEDCUBE_CORE_H
