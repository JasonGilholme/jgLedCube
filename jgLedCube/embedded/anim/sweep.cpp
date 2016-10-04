
#include "sweep.h"

#include <jgLedCube/embedded/core.h>

#include <stdint.h>"


namespace jgLedCube {
    namespace anim {

        namespace sweep_x {

            uint8_t x = 0;

            uint8_t r = LED_CUBE_MAX_INTENSITY;
            uint8_t g = LED_CUBE_MAX_INTENSITY;
            uint8_t b = LED_CUBE_MAX_INTENSITY;

            int8_t i = 1;

            bool pump(){
                // Bump the value
                x += i;
                if (x > LED_CUBE_X_DIMENSION){
                    x = LED_CUBE_X_DIMENSION - 1;
                    i = -1;
                }

                if (x == 0){
                    x = 1;
                    i = 1;
                    return true;
                }

                // Set the data
                for(uint8_t y=0; y < LED_CUBE_Y_DIMENSION; y++){
                    for(uint8_t z=0; z < LED_CUBE_Z_DIMENSION; z++){
                        jgLedCube::core::setLed(x, y, z, r, g, b);
                    }
                }

                return false;
            }

            void reset(){
                x = 0;
                r = LED_CUBE_MAX_INTENSITY;
                g = LED_CUBE_MAX_INTENSITY;
                b = LED_CUBE_MAX_INTENSITY;
            }

            void setIntensities(uint8_t _r, uint8_t _g, uint8_t _b){
                r = _r;
                g = _g;
                b = _b;
            }
        }

        namespace sweep_y {

            uint8_t y = 0;

            uint8_t r = LED_CUBE_MAX_INTENSITY;
            uint8_t g = LED_CUBE_MAX_INTENSITY;
            uint8_t b = LED_CUBE_MAX_INTENSITY;

            int8_t i = 1;

            bool pump(){
                // Bump the value
                y += i;
                if (y > LED_CUBE_Y_DIMENSION){
                    y = LED_CUBE_Y_DIMENSION - 1;
                    i = -1;
                }
                if (y == 0){
                    y = 1;
                    i = 1;
                    return true;
                }

                // Set the data
                for(uint8_t x=0; x < LED_CUBE_X_DIMENSION; x++){
                    for(uint8_t z=0; z < LED_CUBE_Z_DIMENSION; z++){
                        jgLedCube::core::setLed(x, y, z, r, g, b);
                    }
                }
                return false;
            }

            void reset(){
                y = 0;
                r = LED_CUBE_MAX_INTENSITY;
                g = LED_CUBE_MAX_INTENSITY;
                b = LED_CUBE_MAX_INTENSITY;
            }

            void setIntensities(uint8_t _r, uint8_t _g, uint8_t _b){
                r = _r;
                g = _g;
                b = _b;
            }
        }

        namespace sweep_z {

            uint8_t z = 0;

            uint8_t r = LED_CUBE_MAX_INTENSITY;
            uint8_t g = LED_CUBE_MAX_INTENSITY;
            uint8_t b = LED_CUBE_MAX_INTENSITY;

            int8_t i = 1;

            bool pump(){
                // Bump the value
                z += i;
                if (z > LED_CUBE_Z_DIMENSION){
                    z = LED_CUBE_Z_DIMENSION - 1;
                    i = -1;
                }
                if (z == 0){
                    z = 1;
                    i = 1;
                    return true;
                }

                // Set the data
                for(uint8_t x=0; x < LED_CUBE_X_DIMENSION; x++){
                    for(uint8_t y=0; y < LED_CUBE_Y_DIMENSION; y++){
                        jgLedCube::core::setLed(x, y, z, r, g, b);
                    }
                }
                return false;
            }

            void reset(){
                z = 0;
                r = LED_CUBE_MAX_INTENSITY;
                g = LED_CUBE_MAX_INTENSITY;
                b = LED_CUBE_MAX_INTENSITY;
            }

            void setIntensities(uint8_t _r, uint8_t _g, uint8_t _b){
                r = _r;
                g = _g;
                b = _b;
            }
        }
    }
}
