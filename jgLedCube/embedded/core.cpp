
#include <stdint.h>

#ifdef BUILD_EMBEDDED
    #include <string.h>
#else
    #include <iostream>
    #include <cstring>
#endif

#include "core.h"

namespace jgLedCube {
    namespace core {

        // CONST VARS FOR ARRAY USE
        const uint16_t modBlockSize         = LED_CUBE_MODULATION_BLOCK_SIZE;
        const uint16_t modBlockSize_x2      = LED_CUBE_MODULATION_BLOCK_SIZE_X2;
        const uint16_t modBlockSize_x3      = LED_CUBE_MODULATION_BLOCK_SIZE_X3;
        const uint16_t dataArraySize        = LED_CUBE_DATA_ARRAY_SIZE;

        // THE MAIN DATA ARRAY
        uint8_t dataArray[dataArraySize] = {};

        // VARS FOR THE CURRENT STATE OF TE MULTIPLEXING AND MODULATION
        uint8_t curr_modCycle = 0;
        uint8_t curr_z = 1;
        uint8_t curr_zByte = 1;
        uint16_t curr_modOffset = 0;


        void clear() {
            memset(dataArray, 0, dataArraySize);
        }

        void flood() {
            memset(dataArray, 255, dataArraySize);
        }

        // TODO: Support other hardware configurations
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
            static uint16_t led_id = 0;
            static uint8_t byte_id = 0;
            static uint8_t bit_id = 0;

            led_id = (((z - 1) * LED_CUBE_XY_DIMENSION) + (((y - 1) * LED_CUBE_X_DIMENSION)) + x - 1) * LED_CUBE_N_CHANNELS;
            byte_id = led_id  / 8;
            bit_id = led_id % 8;

            setBit(dataArray[byte_id], bit_id, getBit(r, 0));
            setBit(dataArray[byte_id + modBlockSize], bit_id, getBit(r, 1));
            setBit(dataArray[byte_id + modBlockSize_x2], bit_id, getBit(r, 2));
            setBit(dataArray[byte_id + modBlockSize_x3], bit_id, getBit(r, 3));

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
            setBit(dataArray[byte_id + modBlockSize_x2], bit_id, getBit(b, 2));
            setBit(dataArray[byte_id + modBlockSize_x3], bit_id, getBit(b, 3));
            #endif
        }

        void getLed(uint8_t x, uint8_t y, uint8_t z, uint8_t &r, uint8_t &g, uint8_t &b){
            static uint16_t led_id = 0;
            static uint8_t byte_id = 0;
            static uint8_t bit_id = 0;

            led_id = (((z - 1) * LED_CUBE_XY_DIMENSION) + (((y - 1) * LED_CUBE_X_DIMENSION)) + x - 1) * LED_CUBE_N_CHANNELS;
            byte_id = led_id  / 8;
            bit_id = led_id % 8;

            r = 0;
            setBit(r, 0, getBit(dataArray[byte_id], bit_id));
            setBit(r, 1, getBit(dataArray[byte_id + modBlockSize], bit_id));
            setBit(r, 2, getBit(dataArray[byte_id + modBlockSize_x2], bit_id));
            setBit(r, 3, getBit(dataArray[byte_id + modBlockSize_x3], bit_id));

            #if LED_CUBE_N_CHANNELS >= 2
            bit_id++;
            if (bit_id == 8){
                byte_id++;
                bit_id=0;
            }

            g = 0;
            setBit(g, 0, getBit(dataArray[byte_id], bit_id));
            setBit(g, 1, getBit(dataArray[byte_id + modBlockSize], bit_id));
            setBit(g, 2, getBit(dataArray[byte_id + modBlockSize_x2], bit_id));
            setBit(g, 3, getBit(dataArray[byte_id + modBlockSize_x3], bit_id));
            #endif

            #if LED_CUBE_N_CHANNELS >= 3
            bit_id++;
            if (bit_id == 8){
                byte_id++;
                bit_id=0;
            }

            b = 0;
            setBit(b, 0, getBit(dataArray[byte_id], bit_id));
            setBit(b, 1, getBit(dataArray[byte_id + modBlockSize], bit_id));
            setBit(b, 2, getBit(dataArray[byte_id + modBlockSize_x2], bit_id));
            setBit(b, 3, getBit(dataArray[byte_id + modBlockSize_x3], bit_id));
            #endif
        }

        #if !BUILD_EMBEDDED /// Altered signature for testing purposes
        void redraw(uint8_t sentData[]) { /// LED_CUBE_MODULATION_BLOCK_SIZE / LED_CUBE_Z_DIMENSION
        #else
        void redraw() {
        #endif
            /// Pre Redraw - Blank pin on the shift registers
            jgLedCube::core::hwPreRedraw();

            /// Push the bits to control which level is on for the multiplexing
            jgLedCube::core::hwPushByte(curr_zByte);

            /// Push out the data for the leds
            int16_t endByte = (((curr_z - 1) * LED_CUBE_XY_DIMENSION * LED_CUBE_N_CHANNELS) / 8) + curr_modOffset ;
            int16_t sendByte = endByte + ((LED_CUBE_XY_DIMENSION * LED_CUBE_N_CHANNELS) / 8) -1;

            #if !BUILD_EMBEDDED
            int i = 0;
            #endif

            for (; sendByte >= endByte; --sendByte) {
                #if !BUILD_EMBEDDED
                sentData[i] = jgLedCube::core::dataArray[sendByte];
                i++;
                #endif

                jgLedCube::core::hwPushByte(jgLedCube::core::dataArray[sendByte]);
            }

            /// Post Redraw - Usually blank pin and latching the shift registers
            jgLedCube::core::hwPostRedraw();

            /// bump the operational vars
            ++curr_z;
            curr_zByte <<= 1;
            if (curr_z > LED_CUBE_Z_DIMENSION) {  /// > compare op because curr_z is 1 based
                curr_zByte = 1;
                curr_z = 1;
                ++curr_modCycle;
            }
            if (curr_modCycle == LED_CUBE_MAX_INTENSITY) {  /// == compare op cause intensities are 0 based
                curr_modCycle = 0;
            }

            /// Set modulation bit based on modulation cycle
            if (curr_modCycle == 0) {
                curr_modOffset = 0;
            }
            if (curr_modCycle == 1) {
                curr_modOffset = modBlockSize;
            }
            if (curr_modCycle == 3) {
                curr_modOffset = modBlockSize_x2;
            }
            if (curr_modCycle == 7) {
                curr_modOffset = modBlockSize_x3;
            }
        }
    }
}
