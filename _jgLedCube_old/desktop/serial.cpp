/// This is the logic implementation for the serial interface.  This should be completely hardware independent.


#include "serial.h"

#include "core.h"
#include "defines.h"


// CommandPatternLength = LED_CUBE_COMMAND_PACKET_SIZE
// TransportPattern = A, A, CommandPattern, ~CP[0], Z

// Data Life Cycle = args -> commandPacket -> transportPacket

// How to send data
// encode_*() -  receives "args" and bakes them into an array that meets the commandPacket spec.
// sendCommand() - takes the commandPacket and send it down the serial line, meeting the transportPacket spec.

// How to get data
// listenForCommand() scrubs the serial input detecting the transportPacket pattern and extracts the commandPacket component.
// decodeCommand() takes that commandPacket, expands it into args and calls the appropriate function.



namespace jgLedCube {
    namespace serial {

        /// Buffers
        uint8_t transportOutBytes[LED_CUBE_TRANSPORT_PACKET_SIZE] = {};
        uint8_t encodeCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE] = {};
        uint8_t decodeCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE] = {};
        const uint8_t transportSB = 85;
        const uint8_t transportEB = 170;

        /// Get the command id from a comman packet
        uint8_t decode_commandId(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            return (inCmdPacket[0] & 15);
        }

        /// clear() Command Format
        ///  CMD ID    /        /    /        /    /        /    /
        /// [ xxxx   xxxx ] [ xxxx xxxx ] [ xxxx xxxx ] [ xxxx xxxx ]
        void encode_clear(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            outCmdPacket[0] = 0 ^ (LED_CUBE_CMD_CLEAR & 15);
            outCmdPacket[1] = 0;
            outCmdPacket[2] = 0;
            outCmdPacket[3] = 0;
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
        void encode_getConfigReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            outCmdPacket[0] = (LED_CUBE_X_DIMENSION << 4) ^ (LED_CUBE_CMD_GET_CONFIG_RETURN & 15);
            outCmdPacket[1] = (LED_CUBE_Z_DIMENSION << 4) ^ (LED_CUBE_Y_DIMENSION & 15);
            outCmdPacket[2] = (LED_CUBE_N_CHANNELS << 6) ^ (LED_CUBE_VERSION & 63);
            outCmdPacket[3] = LED_CUBE_UID;
        }
        void decode_getConfigReturn(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t outArgs[6]){
            outArgs[0] = (inCmdPacket[0] & 240) >> 4;
            outArgs[1] = inCmdPacket[1] & 15;
            outArgs[2] = (inCmdPacket[1] & 240) >> 4;
            outArgs[3] = (inCmdPacket[2] & 192) >> 6;
            outArgs[4] = inCmdPacket[2] & 63;
            outArgs[5] = inCmdPacket[3];
        }

        /// Send / Receive Commands
        ///  These commands work with the TransportPacket Spec
        ///  Transport Packet Spec
        ///   START BYTES       CMD PACKET BYTES     CHECK BYTE   END
        ///  [ SB ] [ SB ]  [ CP[0] ] ... [ CP[N] ]  [ ~CP[0] ]  [ EB ]

        void receiveCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE], uint8_t timeoutSeconds=5){

        }

        void sendCommand(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            // Prepare the transport packet - Start Bytes
            transportOutBytes[0] = transportSB;
            transportOutBytes[1] = transportSB;

            // Pack in the command bytes
            for (uint8_t i=0; i < LED_CUBE_COMMAND_PACKET_SIZE; i++){
                transportOutBytes[i + 2] = outCmdPacket[i];
            }
            // Check byte
            transportOutBytes[LED_CUBE_COMMAND_PACKET_SIZE + 2] = ~(uint8_t)outCmdPacket[0];
            // End byte
            transportOutBytes[LED_CUBE_COMMAND_PACKET_SIZE + 3] = transportEB;

            for (uint8_t i=0; i < LED_CUBE_TRANSPORT_PACKET_SIZE; i++){
                sendByte(transportOutBytes[i]);
            }
        }

        /// ++++++++++ PROCESSING ++++++++++ ///
        void processCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            uint8_t commandId = decode_commandId(inCmdPacket);

            static uint8_t cmdPacket[LED_CUBE_COMMAND_PACKET_SIZE] = {};
            static uint8_t argBuffer[6] = {};

            switch (commandId) {
                case LED_CUBE_CMD_SET_LED:
                    decode_setLed(inCmdPacket, argBuffer);
                    jgLedCube::core::setLed(argBuffer[0], argBuffer[1], argBuffer[2],
                                            argBuffer[3], argBuffer[4], argBuffer[5]);
                    break;

                case LED_CUBE_CMD_SET_MODE:
                    break;

                case LED_CUBE_CMD_GET_CONFIG:
                    jgLedCube::serial::encode_getConfigReturn(cmdPacket);
                    sendCommand(cmdPacket);
                    break;

                case LED_CUBE_CMD_GET_LED:
                    decode_getLed(inCmdPacket, argBuffer);
                    jgLedCube::core::getLed(argBuffer[0], argBuffer[1], argBuffer[2],
                                            argBuffer[3], argBuffer[4], argBuffer[5]);
                    encode_getLedReturn(cmdPacket, argBuffer[3], argBuffer[4], argBuffer[5]);
                    sendCommand(cmdPacket);
                    break;

                case LED_CUBE_CMD_GET_MODES:
                    break;

                case LED_CUBE_CMD_GET_MODE:
                    break;

                case LED_CUBE_CMD_CLEAR:
                    jgLedCube::core::clear();
                    break;

                default:
                    break;
            }
        }
    }
}
