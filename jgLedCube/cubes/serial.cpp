/// This is the logic implementation for the serial interface.  This should be completely hardware independent.

#include <jgLedCube/common/serial.h>
#include <jgLedCube/cubes/serial.h>
#include <jgLedCube/cubes/core.h>


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

        /// ++++++++++ PROCESSING ++++++++++ ///
        void processCommand(uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            uint8_t commandId = jgLedCube::serial::decode_commandId(inCmdPacket);

            static uint8_t cmdPacket[LED_CUBE_COMMAND_PACKET_SIZE] = {};
            static uint8_t argBuffer[6] = {};

            switch (commandId) {
                case LED_CUBE_CMD_SET_LED:
                    jgLedCube::serial::decode_setLed(inCmdPacket, argBuffer);
                    jgLedCube::core::setLed(argBuffer[0], argBuffer[1], argBuffer[2],
                                            argBuffer[3], argBuffer[4], argBuffer[5]);
                    break;

                case LED_CUBE_CMD_SET_MODE:
                    break;

                case LED_CUBE_CMD_GET_CONFIG:
                    jgLedCube::serial::encode_getConfigReturn(cmdPacket,
                                                              LED_CUBE_X_DIMENSION,
                                                              LED_CUBE_Y_DIMENSION,
                                                              LED_CUBE_Z_DIMENSION,
                                                              LED_CUBE_N_CHANNELS,
                                                              LED_CUBE_VERSION,
                                                              LED_CUBE_UID);
                    sendCommand(cmdPacket);
                    break;

                case LED_CUBE_CMD_GET_LED:
                    jgLedCube::serial::decode_getLed(inCmdPacket, argBuffer);
                    jgLedCube::core::getLed(argBuffer[0], argBuffer[1], argBuffer[2],
                                            argBuffer[3], argBuffer[4], argBuffer[5]);
                    jgLedCube::serial::encode_getLedReturn(cmdPacket, argBuffer[3], argBuffer[4], argBuffer[5]);
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
