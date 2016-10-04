
#ifndef JGLEDCUBE_ANIM_FADE_H
#define JGLEDCUBE_ANIM_FADE_H

namespace jgLedCube {
    namespace anim {
        /// Takes the current state of the leds and fades them out.  Returns true when the cube is blank.
        namespace fade_out {
            bool pump();
            void reset();
        }
    }
}

#endif //JGLEDCUBE_ANIM_FADE_H
