
#if defined(ARDUINO_BUILD)
    #include <string.h>
    #include <stdint.h>
#elif defined(STM32_BUILD)
    #include <string.h>
    #include <stdint.h>
#else
    #include <stdint.h>
    #include <iostream>
    #include <cstring>
#endif

#include "core.h"

namespace jgLedCube {
    namespace core {

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
            uint8_t byte_id = (led_id / 8); // * channel;
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
            std::cout << "X_DIMENSION: " << (int) xDimension << std::endl;
            std::cout << "Y_DIMENSION: " << (int) yDimension << std::endl;
            std::cout << "Z_DIMENSION: " << (int) zDimension << std::endl;
            std::cout << "N_CHANNELS: " << (int) nChannels << std::endl;
            std::cout << "_MODULATION_BITS: " << (int) modulationBits << std::endl;
            std::cout << "_MAX_INTENSITY: " << (int) maxIntensity << std::endl;
            std::cout << "_N_ARRAY_BYTES: " << (int) dataArraySize << std::endl;
        }
#endif
    }
}
