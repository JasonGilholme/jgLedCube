/// Serial client & server functions to provide cube communications

#ifndef LED_CUBE_EMBEDDED_SERIAL_H
#define LED_CUBE_EMBEDDED_SERIAL_H


#include <jgLedCube/common/serial.h>
#include <jgLedCube/common/defines.h>

#include <stdint.h>


namespace jgLedCube {
    namespace serial {

        /// ++++++++++ PROCESSING ++++++++++ ///
        void processCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        void receiveCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t timeoutSeconds);
        void sendCommand(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);

        /// ================================================= ///
        ///         Hardware Specific Functions         ///
        /// ================================================= ///

        /// Setups up the serial connection for the hardware
        void init();

        /// Reads a byte of data from RX
        uint8_t receiveByte();

        /// Sends a byte of data down TX
        bool sendBytes(uint8_t data[]);
    }
}


#endif //LED_CUBE_EMBEDDED_SERIAL_H
