/// Serial client & server functions to provide cube communications

#ifndef LED_CUBE_SERIAL_H
#define LED_CUBE_SERIAL_H

#define LED_CUBE_COMMAND_PACKET_SIZE 4

#include <stdint.h>

namespace jgLedCube {
    namespace serial {

        /// ================================================= ///
        ///                      LOGIC                        ///
        /// ================================================= ///

        /// setLed()
        void encode_setLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b);
        void decode_setLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[6]);

        /// getLed()
        void encode_getLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t x, uint8_t y, uint8_t z);
        void decode_getLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[3]);
        void encode_getLedReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t r, uint8_t g, uint8_t b);
        void decode_getLedReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[3]);

        /// getConfig()
        void encode_getConfig();
        void decode_getConfig();
        void encode_getConfigReturn();
        void decode_getConfigReturn();

        /// setMode()
        void encode_setMode();
        void decode_setMode();

        /// getMode()
        void encode_getMode();
        void decode_getMode();
        void encode_getModeReturn();
        void decode_getModeReturn();

        /// getModes()
        void encode_getModes();
        void decode_getModes();
        void encode_getModesReturn();
        void decode_getModesReturn();


        /// ================================================= ///
        ///         Implementation Specific Functions         ///
        /// ================================================= ///

        /// Setups up the serial connection for the hardware
        void init();

        /// Reads a byte of data from RX
        uint8_t readData();

        /// Sends a byte of data down TX
        bool writeData(uint8_t data);
    }
}


#endif //LED_CUBE_SERIAL_H
