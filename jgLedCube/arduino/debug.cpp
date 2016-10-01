/// Debug blink to test on Arduino hardware

#include <Arduino.h>
#include <jgLedCube/core.h>
#include <jgLedCube/anim/debug.h>

void setup(){}

void loop(){
    jgLedCube::core::clear();
    jgLedCube::anim::debug_blink::reset();

    bool done = false;
    while (!done){
        done = jgLedCube::anim::debug_blink::pump();
    }
}
