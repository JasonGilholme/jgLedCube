/// Run all animations through a bunch of cycles to ensure we don't get any runtime errors.

#include <gtest/gtest.h>

#include <jgLedCube/core.h>
#include <jgLedCube/anim/debug.h>
#include <jgLedCube/anim/sweep.h>
#include <jgLedCube/anim/fade.h>

TEST(Anim, Debug) {
    bool done = false;

    jgLedCube::core::clear();
    jgLedCube::anim::debug_blink::reset();

    while (!done){
        done = jgLedCube::anim::debug_blink::pump();
    }
}

//TEST(Anim, FadeOut) {
//    bool done = false;
//
//    jgLedCube::core::clear();
//
//    for(uint8_t z=0; z < LED_CUBE_Z_DIMENSION; z++){
//        for(uint8_t y=0; y < LED_CUBE_Y_DIMENSION; y++){
//            for(uint8_t x=0; x < LED_CUBE_X_DIMENSION; x++) {
//                jgLedCube::core::setLed(x, y, z, 15, 15, 15);
//            }
//        }
//    }
//
//
//    jgLedCube::anim::fade_out::reset();
//    while (!done){
//        done = jgLedCube::anim::fade_out::pump();
//    }
//}
//
//TEST(Anims, SweepX) {
//    bool done = false;
//
//    // SWEEP X
//    jgLedCube::core::clear();
//    jgLedCube::anim::sweep_x::reset();
//
//    while (!done){
//        jgLedCube::anim::sweep_x::setIntensities(5, 10, 15);
//        done = jgLedCube::anim::sweep_x::pump();
//    }
//}
//
//
//TEST(Anim, SweepY) {
//    bool done = false;
//
//    // SWEEP Y
//    jgLedCube::core::clear();
//    jgLedCube::anim::sweep_y::reset();
//
//    while (!done){
//        jgLedCube::anim::sweep_y::setIntensities(5, 10, 15);
//        done = jgLedCube::anim::sweep_y::pump();
//    }
//}
//
//
//TEST(Anim, SweepZ) {
//    bool done = false;
//
//    // SWEEP Z
//    jgLedCube::core::clear();
//    jgLedCube::anim::sweep_z::reset();
//
//    while (!done){
//        jgLedCube::anim::sweep_z::setIntensities(5, 10, 15);
//        done = jgLedCube::anim::sweep_z::pump();
//    }
//}
