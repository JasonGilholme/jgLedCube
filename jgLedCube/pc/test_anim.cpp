/// Run all animations through a bunch of cycles to ensure we don't get any runtime errors.

#include <gtest/gtest.h>

#include <jgLedCube/core.h>
#include <jgLedCube/anim/debug.h>


TEST(Anim, Debug) {
    bool done = false;

    jgLedCube::core::clear();
    jgLedCube::anim::debug_blink::reset();

    while (!done){
        done = jgLedCube::anim::debug_blink::pump();
    }
}
