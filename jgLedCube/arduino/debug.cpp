/// Debug blink to test on Arduino hardware

#include <Arduino.h>
#include <jgLedCube/core.h>
#include <jgLedCube/anim/debug.h>

void setup(){

}

void loop(){
    jgLedCube::core::setLed(1, 1, 1, 15, 15, 15);
}
