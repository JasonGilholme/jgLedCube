/// Core data functions & variables for cube operation.

#ifndef JGLEDCUBE_EMBEDDED_CORE_H
#define JGLEDCUBE_EMBEDDED_CORE_H

#include <jgLedCube/embedded/defines.h>

#include <stdint.h>

// TODO: Could this be all header? and make use of inline functions - this will be high frequency.

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

#endif //JGLEDCUBE_EMBEDDED_CORE_H
