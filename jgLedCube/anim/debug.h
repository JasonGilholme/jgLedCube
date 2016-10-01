//
// Created by jase on 1/10/16.
//

#ifndef JGLEDCUBE_ANIM_DEBUG_H
#define JGLEDCUBE_ANIM_DEBUG_H

namespace jgLedCube {
    namespace anim {
        /// Blinks every led in the array on every channel at every intensity level
        namespace debug_blink {
            bool pump();
            void reset();
        }

        /// Turns on every led at maximum intensity all at once. Cycles through All channels individually, and then mixes them.
        namespace debug_const {
            bool pump();
            void reset();
        }
    }
}

#endif //JGLEDCUBE_ANIM_DEBUG_H
