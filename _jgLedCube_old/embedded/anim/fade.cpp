
#include "fade.h"

#include <jgLedCube/embedded/core.h>

#include <stdint.h>


namespace jgLedCube {
    namespace anim {

        /// Takes the current state of the leds and fades them out.  Returns true when the cube is blank.
        namespace fade_out {
            bool pump(){
                uint8_t r = 0;
                uint8_t g = 0;
                uint8_t b = 0;

                bool all_off = true;

                for(uint8_t z=0; z < LED_CUBE_Z_DIMENSION; z++){
                    for(uint8_t y=0; y < LED_CUBE_Y_DIMENSION; y++){
                        for(uint8_t x=0; x < LED_CUBE_X_DIMENSION; x++) {
                            jgLedCube::core::getLed(x, y, z, r, g, b);

                            if (r > 0) r--;
                            if (g > 0) g--;
                            if (b > 0) b--;

                            jgLedCube::core::setLed(x, y, z, r, g, b);

                            if (r + g + b){
                                all_off=false;
                            }
                        }
                    }
                }
                return all_off;
            }

            void reset(){}
        }
    }
}
