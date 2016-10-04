
#ifndef JGLEDCUBE_ANIM_SWEEP_H
#define JGLEDCUBE_ANIM_SWEEP_H

#include <stdint.h>"

namespace jgLedCube {
    namespace anim {

        /// Moves a square on the YZ plane along the X axis
        namespace sweep_x {
            bool pump();
            void reset();
            void setIntensities(uint8_t _r, uint8_t _g, uint8_t _b);
        }

        /// Moves a square on the XZ plane along the Y axis
        namespace sweep_y {
            bool pump();
            void reset();
            void setIntensities(uint8_t _r, uint8_t _g, uint8_t _b);
        }

        /// Moves a square on the XY plane along the Z axis
        namespace sweep_z {
            bool pump();
            void reset();
            void setIntensities(uint8_t _r, uint8_t _g, uint8_t _b);
        }
    }
}

#endif //JGLEDCUBE_ANIM_SWEEP_H
