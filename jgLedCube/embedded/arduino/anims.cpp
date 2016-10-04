/// Runs through all the animations for testing purposes

#include <Arduino.h>

#include <jgLedCube/core.h>

#include <jgLedCube/anim/debug.h>


void setup(){}

void loop(){
    bool anim_done = false;

    // debug_blink
    jgLedCube::core::clear();
    jgLedCube::anim::debug_blink::reset();

    anim_done = false;
    while (!anim_done){
        anim_done = jgLedCube::anim::debug_blink::pump();
    }

    // debug_const
    jgLedCube::core::clear();
    jgLedCube::anim::debug_const::reset();

    anim_done = false;
    while (!anim_done){
        anim_done = jgLedCube::anim::debug_const::pump();
    }

}
