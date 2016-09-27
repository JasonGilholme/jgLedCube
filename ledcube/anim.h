/// Animations for the cube that work on top of the core lib.

#ifndef LED_CUBE_ANIM_H
#define LED_CUBE_ANIM_H

#include "core.h"

// TODO: Break this out into separate implementations in a sub dir?

namespace jgLedCube {
    namespace animation {

        void sin_wave(float phaseInc, float rotationInc, int sleep);
        void pong(uint8_t sleep);
        void tornado(uint8_t sleep);
        void disolve_fade(unsigned int fadeTime, unsigned int sleep);
        void sweep_x(uint8_t sleep);
        void sweep_y(uint8_t sleep);
        void sweep_z(uint8_t sleep);
        void matrix();
        void fade_all(uint8_t fadeRate);
        void test_constant();
        void test_blink();

    }
}

#endif //LED_CUBE_ANIM_H
