
#include <stdint.h>

#if defined(ARDUINO_BUILD)
    #include <string.h>
#elif defined(STM32_BUILD)
    #include <string.h>
#else
    #include <iostream>
    #include <cstring>
#endif

#include "core.h"

namespace jgLedCube {
    namespace core {

        const char* cubeName = LED_CUBE_NAME;
        const double cubeUid = LED_CUBE_UID;
        const double cubeVersion = LED_CUBE_VERSION;

        // CUBE CONFIGURATION
        const uint8_t xDimension = LED_CUBE_X_DIMENSION;
        const uint8_t yDimension = LED_CUBE_Y_DIMENSION;
        const uint8_t zDimension = LED_CUBE_Z_DIMENSION;
        const uint8_t nChannels = LED_CUBE_N_CHANNELS;

        // VARS FOR INTERNAL WORKINGS
        const uint8_t xyDimension = LED_CUBE_XY_DIMENSION;
        const uint8_t xyzDimension = LED_CUBE_XYZ_DIMENSION;
        const uint8_t modulationBits = LED_CUBE_MODULATION_BITS;
        const uint8_t maxIntensity = LED_CUBE_MAX_INTENSITY;
        const uint8_t modBlockSize = LED_CUBE_MODULATION_BLOCK_SIZE;
        const uint8_t dataArraySize = LED_CUBE_DATA_ARRAY_SIZE;

        // THE MAIN DATA ARRAY
        uint8_t dataArray[dataArraySize] = {};

        void setBit(uint8_t &b, const uint8_t &n, const uint8_t &v) {
            b ^= (-v ^ b) & (1 << n);
        }

        uint8_t getBit(uint8_t b, uint8_t n) {
            return (b >> n) & 1;
        }

        void clear() {
            memset(dataArray, 0, dataArraySize);
        }

        void setLed(uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b) {
            /* DATA LAYOUT NOTES
             *
             * Each bit represents the state of a single channel of a single led.
             * Progresses from (1,1,1) through x, y, then z. This is then repeated
             * for each modulation bit. e.g:
             *
             * Channel: R,G,B R,G,B ... R,G,B R,G,B -> Next Modulation Block
             * Co-Ord:  1,1,1 2,1,1 ... 3,4,4 4,4,4
             *
             * This is ultimately defined by the hardware configuration.
             * An alternative is to handle the channels separately, and do R111 -> R444,
             * then B111 -> B444 etc. This is then repeated for each modulation bit as well.
             *
             * */
            uint8_t led_id = ((z - 1) * xyDimension) + (((y - 1) * xDimension)) + x - 1;
            uint8_t byte_id = (led_id / 8);
            uint8_t bit_id = led_id % 8;

            // SET THE 4 MODULATION BITS
            setBit(dataArray[byte_id], bit_id,getBit(r, 0));
            setBit(dataArray[byte_id + modBlockSize], bit_id, getBit(r, 1));
            setBit(dataArray[byte_id + (modBlockSize * 2)], bit_id, getBit(r, 2));
            setBit(dataArray[byte_id + (modBlockSize * 3)], bit_id, getBit(r, 3));

#if LED_CUBE_N_CHANNELS >= 2
            bit_id++;
            if (bit_id == 8){
                byte_id++;
                bit_id=0;
            }

            setBit(dataArray[byte_id], bit_id, getBit(g, 0));
            setBit(dataArray[byte_id + modBlockSize], bit_id, getBit(g, 1));
            setBit(dataArray[byte_id + (modBlockSize * 2)], bit_id, getBit(g, 2));
            setBit(dataArray[byte_id + (modBlockSize * 3)], bit_id, getBit(g, 3));
#endif
#if LED_CUBE_N_CHANNELS >= 3
            bit_id++;
            if (bit_id == 8){
                byte_id++;
                bit_id=0;
            }

            setBit(dataArray[byte_id], bit_id, getBit(b, 0));
            setBit(dataArray[byte_id + modBlockSize], bit_id, getBit(b, 1));
            setBit(dataArray[byte_id + (modBlockSize * 2)], bit_id, getBit(b, 2));
            setBit(dataArray[byte_id + (modBlockSize * 3)], bit_id, getBit(b, 3));
#endif
        }

#ifdef PC_BUILD
        void printData() {
            for (int _byte_index = 0; _byte_index < dataArraySize; _byte_index++) {
                uint8_t _byte = dataArray[_byte_index];
                for (uint8_t _bit_index = 0; _bit_index < 8; _bit_index++) {
                    std::cout
                            << _byte_index
                            << "  "
                            << (int) _bit_index
                            << "  "
                            << (int) getBit(_byte, _bit_index)
                            << std::endl;
                }
            }
        }

        void printConfig() {
            std::cout << "CUBE_NAME: "              << LED_CUBE_NAME                    << std::endl;
            std::cout << "CUBE_UID: "               << LED_CUBE_UID                     << std::endl;
            std::cout << "CUBE_VERSION: "           << LED_CUBE_VERSION                 << std::endl;
            std::cout << "X_DIMENSION: "            << LED_CUBE_X_DIMENSION             << std::endl;
            std::cout << "Y_DIMENSION: "            << LED_CUBE_Y_DIMENSION             << std::endl;
            std::cout << "Z_DIMENSION: "            << LED_CUBE_Z_DIMENSION             << std::endl;
            std::cout << "N_CHANNELS: "             << LED_CUBE_N_CHANNELS              << std::endl;
            std::cout << "MODULATION_BLOCK_SIZE: "  << LED_CUBE_MODULATION_BLOCK_SIZE   << std::endl;
            std::cout << "DATA_ARRAY_SIZE: "        << LED_CUBE_DATA_ARRAY_SIZE         << std::endl;
        }
#endif
    }
}
