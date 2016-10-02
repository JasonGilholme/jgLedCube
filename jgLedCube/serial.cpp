/// This is the logic implementation for the serial interface.  This should be completely hardware independent.


#include "serial.h"

#include "core.h"
#include "defines.h"


namespace jgLedCube {
    namespace serial {

        // CommandPatternLength = LED_CUBE_COMMAND_PACKET_SIZE
        // TransportPattern = A, A, CommandPattern, ~CP[0], Z

        // Data Life Cycle = args -> commandPacket -> transportPacket

        // How to send data
        // encode_*() -  receives "args" and bakes them into an array that meets the commandPacket spec.
        // sendCommand() - takes the commandPacket and send it down the serial line, meeting the transportPacket spec.

        // How to get data
        // listenForCommand() scrubs the serial input detecting the transportPacket pattern and extracts the commandPacket component.
        // decodeCommand() takes that commandPacket, expands it into args and calls the appropriate function.

        /// Buffers
        uint8_t serialInput[12] = {};
        uint8_t encodeCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE] = {};
        uint8_t decodeCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE] = {};


        /// Get the command id from a comman packet
        uint8_t decode_commandId(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            return (inCmdPacket[0] & 15);
        }


        /// setLed() Command Format
        ///  CMD ID    X        Y    Z        R    G        B    /
        /// [ xxxx   xxxx ] [ xxxx xxxx ] [ xxxx xxxx ] [ xxxx xxxx ]
        void encode_setLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                           uint8_t x, uint8_t y, uint8_t z,
                           uint8_t r, uint8_t g, uint8_t b){
            outCmdPacket[0] = (x << 4) ^ (LED_CUBE_CMD_SET_LED & 15);
            outCmdPacket[1] = (z << 4) ^ (y & 15);
            outCmdPacket[2] = (g << 4) ^ (r & 15);
            outCmdPacket[3] = 0 ^ (b & 15);
        }
        void decode_setLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[6]){
            outArgs[0] = (inCmdPacket[0] & 240) >> 4;
            outArgs[1] = inCmdPacket[1] & 15;
            outArgs[2] = (inCmdPacket[1] & 240) >> 4;
            outArgs[3] = inCmdPacket[2] & 15;
            outArgs[4] = (inCmdPacket[2] & 240) >> 4;
            outArgs[5] = inCmdPacket[3] & 15;
        }


        /// getLed()
        ///  CMD ID    X        Y    Z        /    /        /    /
        /// [ xxxx   xxxx ] [ xxxx xxxx ] [ xxxx xxxx ] [ xxxx xxxx ]
        void encode_getLed(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                           uint8_t x, uint8_t y, uint8_t z){
            outCmdPacket[0] = (x << 4) ^ (LED_CUBE_CMD_GET_LED & 15);
            outCmdPacket[1] = (z << 4) ^ (y & 15);
            outCmdPacket[2] = 0;
            outCmdPacket[3] = 0;
        }
        void decode_getLed(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[3]){
            outArgs[0] = (inCmdPacket[0] & 240) >> 4;
            outArgs[1] = inCmdPacket[1] & 15;
            outArgs[2] = (inCmdPacket[1] & 240) >> 4;
        }


        /// getLed() Return
        ///  CMD ID    R        G    B        /    /        /    /
        /// [ xxxx   xxxx ] [ xxxx xxxx ] [ xxxx xxxx ] [ xxxx xxxx ]
        void encode_getLedReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                 uint8_t r, uint8_t g, uint8_t b){
            outCmdPacket[0] = (r << 4) ^ (LED_CUBE_CMD_GET_LED_RETURN & 15);
            outCmdPacket[1] = (b << 4) ^ (g & 15);
            outCmdPacket[2] = 0;
            outCmdPacket[3] = 0;
        }
        void decode_getLedReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[3]){
            outArgs[0] = (inCmdPacket[0] & 240) >> 4;
            outArgs[1] = inCmdPacket[1] & 15;
            outArgs[2] = (inCmdPacket[1] & 240) >> 4;
        }


        /// getConfig()
        ///  CMD ID    /        /    /        /    /        /    /
        /// [ xxxx   xxxx ] [ xxxx xxxx ] [ xxxx xxxx ] [ xxxx xxxx ]
        void encode_getConfig(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            outCmdPacket[0] = 0 ^ (LED_CUBE_CMD_GET_CONFIG & 15);
            outCmdPacket[1] = 0;
            outCmdPacket[2] = 0;
            outCmdPacket[3] = 0;
        }


        /// getConfig() Return
        ///  CMD ID    R        G    B       N    V          ID
        /// [ xxxx   xxxx ] [ xxxx xxxx ] [ xx xxxxxx ] [ xxxxxxxx ]
        void encode_getConfigReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                    uint8_t x, uint8_t y, uint8_t z,
                                    uint8_t nchannels, uint8_t version, uint8_t uid){
            outCmdPacket[0] = (x << 4) ^ (LED_CUBE_CMD_GET_CONFIG_RETURN & 15);
            outCmdPacket[1] = (z << 4) ^ (y & 15);
            outCmdPacket[2] = (nchannels << 6) ^ (version & 63);
            outCmdPacket[3] = uid;
        }
        void decode_getConfigReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[6]){
            outArgs[0] = (inCmdPacket[0] & 240) >> 4;
            outArgs[1] = inCmdPacket[1] & 15;
            outArgs[2] = (inCmdPacket[1] & 240) >> 4;
            outArgs[3] = (inCmdPacket[2] & 192) >> 6;
            outArgs[4] = inCmdPacket[2] & 63;
            outArgs[5] = inCmdPacket[3];
        }
    }
}
