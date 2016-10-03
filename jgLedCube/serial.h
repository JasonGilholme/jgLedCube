/// Serial client & server functions to provide cube communications

#ifndef LED_CUBE_SERIAL_H
#define LED_CUBE_SERIAL_H

#define LED_CUBE_COMMAND_PACKET_SIZE 4
#define LED_CUBE_TRANSPORT_PACKET_SIZE LED_CUBE_COMMAND_PACKET_SIZE + 4

#include <stdint.h>

namespace jgLedCube {
    namespace serial {

        extern uint8_t transportOutBytes[LED_CUBE_TRANSPORT_PACKET_SIZE];
        extern uint8_t encodeCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
        extern uint8_t decodeCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
        extern const uint8_t transportSB;
        extern const uint8_t transportEB;


        /// ================================================= ///
        ///                      LOGIC                        ///
        /// ================================================= ///

        /// Get's the command id from a command packet
        uint8_t decode_commandId(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);

        /// clear()
        void encode_clear(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);

        /// setLed()
        void encode_setLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b);
        void decode_setLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[6]);

        /// getLed()
        void encode_getLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t x, uint8_t y, uint8_t z);
        void decode_getLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[3]);
        void encode_getLedReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t r, uint8_t g, uint8_t b);
        void decode_getLedReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[3]);

        /// getConfig()
        void encode_getConfig(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        void encode_getConfigReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        void decode_getConfigReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[6]);

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

        /// ++++++++++ PROCESSING ++++++++++ ///
        void processCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        void receiveCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t timeoutSeconds);
        void sendCommand(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);

        /// ================================================= ///
        ///         Implementation Specific Functions         ///
        /// ================================================= ///

        /// Setups up the serial connection for the hardware
        void init();

        /// Reads a byte of data from RX
        uint8_t receiveByte();

        /// Sends a byte of data down TX
        bool sendByte(uint8_t data);
    }
}


#endif //LED_CUBE_SERIAL_H
