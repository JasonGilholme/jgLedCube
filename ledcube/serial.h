/// Serial client & server functions that allow remote control of an led cube.

#ifndef LED_CUBE_SERIAL_H
#define LED_CUBE_SERIAL_H

#include "core.h"

namespace jgLedCube {
    namespace client {
        /// Decode commands that have been retrieved off the serial via a hardware specific implementation. (Arduino, STM32 etc)
    }

    namespace server {
        /// Encode commands into a data stream to go out via serial.
    }
}
#endif //LED_CUBE_SERIAL_H
