/// Core data functions & variables for cube operation.

#ifndef JGLEDCUBE_EMBEDDED_CORE_H
#define JGLEDCUBE_EMBEDDED_CORE_H

#include <jgLedCube/embedded/defines.h>

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
    }
}

#endif //JGLEDCUBE_EMBEDDED_CORE_H
