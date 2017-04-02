### LED Cube Animations

These animations are all designed to be called inside a loop of some sort. e.g:

    jgLedCube::core::clear();
    jgLedCube::anim::debug_blink::reset();
    
    bool done = false;
    
    while (!done){
        done = jgLedCube::anim::debug_blink::pump();
    }

They maintain their own state, and each individual call to pump() will make it progress through it's own cycle. Each call will return a boolean value informing when a complete cycle is completed, allowing for logical transitions between different animations;

They also provide a reset() function, which will put the anim back to it's initial state.
