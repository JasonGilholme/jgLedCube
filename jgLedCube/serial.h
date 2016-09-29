/// Serial client & server functions that allow remote control of an led cube.

#ifndef LED_CUBE_SERIAL_H
#define LED_CUBE_SERIAL_H

#include "core.h"

namespace jgLedCube {
    namespace serial {
        /// Serial init
        void init();

        /// Read a packet of data
        char read();

        /// Send a packet of data
        void write(char data);

        /// Listens for serial data, interprets it and executes a command.
        void processCommand();
    }
}
#endif //LED_CUBE_SERIAL_H
