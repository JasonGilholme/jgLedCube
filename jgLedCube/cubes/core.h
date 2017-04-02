/// Core data functions & variables for cube operation.

#ifndef JGLEDCUBE_EMBEDDED_CORE_H
#define JGLEDCUBE_EMBEDDED_CORE_H

#include <jgLedCube/cubes/defines.h>
//#include <jgLedCube/embedded/hardware.h>

#include <stdint.h>

namespace jgLedCube {
    namespace core {

        // THE MAIN DATA ARRAY
        extern uint8_t dataArray[];

        #if !BUILD_EMBEDDED  /// Expose some internal vars for testing
        extern uint8_t curr_modCycle;
        extern uint8_t curr_z;
        extern uint8_t curr_zByte;
        extern uint16_t curr_modOffset;
        #endif

        // KEY FUNCTIONS FOR SETTING DATA ON THE CUBE
        void setLed(uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b);
        void getLed(uint8_t x, uint8_t y, uint8_t z, uint8_t &r, uint8_t &g, uint8_t &b);
        void clear();
        void flood();

        // REDRAW DATA ON THE CUBE - CALLED REPEATEDLY VIA A HARDWARE INTERRUPT
        #if !BUILD_EMBEDDED  /// Atlered redraw() signature for testing
        void redraw(uint8_t sendData[]);  /// LED_CUBE_MODULATION_BLOCK_SIZE
        #else
        void redraw();
        #endif

        // BIT GETTER AND SETTER
        inline void setBit(uint8_t &b, const uint8_t &n, const uint8_t &v) {
            b ^= (-v ^ b) & (1 << n);
        }
        uint8_t inline getBit(const uint8_t &b, const uint8_t &n) {
            return (b >> n) & (uint8_t)1;
        }

        /// Hardware Specific Functions
        void hwPushByte(uint8_t data);
        void hwPreRedraw();
        void hwPostRedraw();

        // LUT FOR MAPPING LED IDS ONTO THE MODULAR COLUMN BOARD
        // TODO: Fill out these numbers based on the hardware
        static const uint8_t ledIdLut[24] = {
                0,      /// 0,
                1,      /// 1,      x1, y1
                2,      /// 2,

                3,      /// 3,
                4,      /// 4,      x2, y1
                5,      /// 5,

                6,      /// 6,
                7,      /// 7,      x3, y1
                8,      /// 8,

                9,      /// 9,
                10,     /// 10,     x4, y1
                11,     /// 11,

                12,     /// 12,
                13,     /// 13,     x1, y2
                14,     /// 14,

                15,     /// 15,
                16,     /// 16,     x2, y2
                17,     /// 17,

                18,     /// 18,
                19,     /// 19,     x3, y2
                20,     /// 20,

                21,     /// 21,
                22,     /// 22,     x4, y2
                23,     /// 23,
        };
    }
}

#endif //JGLEDCUBE_EMBEDDED_CORE_H
