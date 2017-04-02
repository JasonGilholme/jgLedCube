/// Debug blink to test on Arduino hardware

#include <Arduino.h>
#include <jgLedCube/embedded/core.h>
#include <jgLedCube/embedded/anim/debug.h>

void setup(){}

void loop(){
    jgLedCube::core::clear();
    jgLedCube::anim::debug_blink::reset();

    bool done = false;
    while (!done){
        done = jgLedCube::anim::debug_blink::pump();
    }
}
