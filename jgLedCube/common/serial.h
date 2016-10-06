/// Serial client & server functions to provide cube communications

#ifndef LED_CUBE_COMMON_SERIAL_H
#define LED_CUBE_COMMON_SERIAL_H

#include <jgLedCube/common/defines.h>

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
        void encode_setLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                           uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b);
        void decode_setLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                           uint8_t outArgs[6]);

        /// getLed()
        void encode_getLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                           uint8_t x, uint8_t y, uint8_t z);
        void decode_getLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                           uint8_t outArgs[3]);
        void encode_getLedReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                 uint8_t r, uint8_t g, uint8_t b);
        void decode_getLedReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                 uint8_t outArgs[3]);

        /// getConfig()
        void encode_getConfig(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        void encode_getConfigReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                    uint8_t xDimension, uint8_t yDimension, uint8_t zDimension,
                                    uint8_t nChannels, uint8_t version, uint8_t uid);
        void decode_getConfigReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                    uint8_t outArgs[6]);

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



        /// Get the command packet from the transport packet
        void deconstructTransportPacket(uint8_t inTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE],
                                        uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        /// Put the command packet into the transport packet for shipping
        void constructTransportPacket(uint8_t outTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE],
                                      uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
        /// Send the transport packet down the serial line
        void sendTransportPacket(uint8_t outTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE]);
        /// Read the serial line until a packet is found or no serial data is available
        bool receiveTransportPacket(uint8_t inTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE]);

        /// Read a byte off the serial line
        uint8_t readByte();

        /// Is there serial data available?
        bool serialAvailable();

        void init();

        /// TODO:  move to embedded?
//        void processCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]);
    }
}

#endif //LED_CUBE_COMMON_SERIAL_H
