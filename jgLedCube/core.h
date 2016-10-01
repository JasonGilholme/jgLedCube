/// Core data functions & variables for cube operation.

#ifndef JGLEDCUBE_CORE_H
#define JGLEDCUBE_CORE_H

#define LED_CUBE_XY_DIMENSION LED_CUBE_X_DIMENSION * LED_CUBE_Y_DIMENSION
#define LED_CUBE_XYZ_DIMENSION LED_CUBE_XY_DIMENSION * LED_CUBE_Y_DIMENSION
#define LED_CUBE_MODULATION_BITS 4
#define LED_CUBE_MAX_INTENSITY 15
#define LED_CUBE_MODULATION_BLOCK_SIZE LED_CUBE_XYZ_DIMENSION / 8.0 * LED_CUBE_N_CHANNELS
#define LED_CUBE_MODULATION_BLOCK_SIZE_X2 LED_CUBE_MODULATION_BLOCK_SIZE * 2
#define LED_CUBE_MODULATION_BLOCK_SIZE_X3 LED_CUBE_MODULATION_BLOCK_SIZE * 3
#define LED_CUBE_DATA_ARRAY_SIZE LED_CUBE_MODULATION_BLOCK_SIZE * LED_CUBE_MODULATION_BITS

#include <stdint.h>

namespace jgLedCube {
    namespace core {
        // CUBE IDENTIFICATION
        extern const char* cubeName;
        extern const double cubeUid;
        extern const double cubeVersion;

        // CUBE CONFIGURATION
        extern const uint8_t xDimension;
        extern const uint8_t yDimension;
        extern const uint8_t zDimension;
        extern const uint8_t nChannels;

        // THE MAIN DATA ARRAY
        extern uint8_t dataArray[];

        // KEY FUNCTIONS FOR SETTING DATA ON THE CUBE
        void setLed(uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b);
        void setLedFloat(float x, float y, float z, uint8_t r, uint8_t g, uint8_t b);
        void clear();
        void getLed(uint8_t x, uint8_t y, uint8_t z, uint8_t &r, uint8_t &g, uint8_t &b);

        // GET & SET BITS IN A BYTE
        void setBit(uint8_t &b, const uint8_t &n, const uint8_t &v);
        uint8_t getBit(uint8_t b, uint8_t n);

        // DEBUG PRINTS
        void printConfig();
        void printData();
    }
}

#endif //JGLEDCUBE_CORE_H
