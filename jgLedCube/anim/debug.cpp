
#include <jgLedCube/core.h>


namespace jgLedCube {
    namespace anim {
        namespace debug_blink {

            uint8_t x = 1;
            uint8_t y = 1;
            uint8_t z = 1;

            uint8_t r = 0;
            uint8_t g = 0;
            uint8_t b = 0;

            uint8_t intensity = 0;
            uint8_t channel = 0;

            bool has_finished = false;

            bool pump(){
                has_finished = false;

                // Bump the data values
                intensity++;
                if (intensity > LED_CUBE_MAX_INTENSITY){
                    channel++;
                    intensity = 0;
                }

                if (channel > LED_CUBE_N_CHANNELS){
                    channel = 1;
                    x++;
                }

                if (x > LED_CUBE_X_DIMENSION){
                    x = 1;
                    y++;
                }

                if (y > LED_CUBE_Y_DIMENSION){
                    y = 1;
                    z++;
                }

                if (z > LED_CUBE_Z_DIMENSION){
                    x = 1;
                    y = 1;
                    z = 1;
                    has_finished = true;
                }

                // SET THE INTENSITIES
                r = channel == 1 ? intensity : 0;
                g = channel == 2 ? intensity : 0;
                b = channel == 3 ? intensity : 0;

                // Put the current values into the array
                jgLedCube::core::clear();
                jgLedCube::core::setLed(x, y, z, r, g, b);

                return has_finished;
            }

            void reset(){
                x = 1;
                y = 1;
                z = 1;
                intensity = 0;
                channel = 0;
            }
        }

        namespace debug_const {
            bool pump(){};
            void reset(){};
        }
    }
}
