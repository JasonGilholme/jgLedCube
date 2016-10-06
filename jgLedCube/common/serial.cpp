/// This is the logic implementation for the serial interface.  This should be completely hardware independent.

#include "serial.h"


namespace jgLedCube {
    namespace serial {

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
        void encode_getConfigReturn(uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE],
                                    uint8_t xDimension, uint8_t yDimension, uint8_t zDimension,
                                    uint8_t nChannels, uint8_t version, uint8_t uid){
            outCmdPacket[0] = (xDimension << 4) ^ (LED_CUBE_CMD_GET_CONFIG_RETURN & 15);
            outCmdPacket[1] = (zDimension << 4) ^ (yDimension & 15);
            outCmdPacket[2] = (nChannels << 6) ^ (version & 63);
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

        /// Send / Receive Commands
        ///  These commands work with the TransportPacket Spec
        ///  Transport Packet Spec
        ///   START BYTES       CMD PACKET BYTES     CHECK BYTE   END
        ///  [ SB ] [ SB ]  [ CP[0] ] ... [ CP[N] ]  [ ~CP[0] ]  [ EB ]
        void deconstructTransportPacket(uint8_t inTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE],
                                        uint8_t inCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            inCmdPacket[0] = inTransportPacket[2];
            inCmdPacket[1] = inTransportPacket[3];
            inCmdPacket[2] = inTransportPacket[4];
            inCmdPacket[3] = inTransportPacket[5];
        }

        void constructTransportPacket(uint8_t outTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE],
                                      uint8_t outCmdPacket[LED_CUBE_COMMAND_PACKET_SIZE]){
            // Prepare the transport packet - Start Bytes
            outTransportPacket[0] = transportSB;
            outTransportPacket[1] = transportSB;

            // Pack in the command bytes
            for (uint8_t i=0; i < LED_CUBE_COMMAND_PACKET_SIZE; i++){
                outTransportPacket[i + 2] = outCmdPacket[i];
            }
            // Check byte
            outTransportPacket[LED_CUBE_COMMAND_PACKET_SIZE + 2] = ~(uint8_t)outCmdPacket[0];
            // End byte
            outTransportPacket[LED_CUBE_COMMAND_PACKET_SIZE + 3] = transportEB;
        }

        bool receiveTransportPacket(uint8_t inTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE]) {
            static uint8_t buffer[20] = {255};  // TODO: Find a better way of doing this init
            // need to pre fill with serial data to get a valid return from the first shot
            bool noSerial = false;
            uint8_t tempByte = 0;

            if (buffer[0] == 255){
                for (int k = 0; k < 20; ++k) {
                    if (noSerial){
                        tempByte = 0;

                    }else{
                        tempByte = readByte();
                    }

                    if (tempByte) {
                        buffer[k] = tempByte;
                    }
                    else{
                        noSerial = true;
                        buffer[k] = 0;
                    }
                }
            }

            int8_t startIndex = -1;
            bool foundPacket = false;

            noSerial = false;

            while (!foundPacket and !noSerial) {  /// or serial not available

                /// Identify packet
                startIndex = -1;
                for (int i = 0; i < 12; ++i) {

                    if (buffer[i] == transportSB &&
                        buffer[i + 1] == transportSB &&
                        buffer[i + 7] == transportEB &&
                        buffer[i + 6] == (uint8_t) ~buffer[i + 2]) {

                        foundPacket = true;
                        startIndex = i;

                        for (int j = 0; j < LED_CUBE_TRANSPORT_PACKET_SIZE; j++) {
                            inTransportPacket[j] = buffer[i + j];
                            buffer[i + j] = 0;
                        }
                        break;
                    }
                }
        
                /// Slide values along to remove the packet we just grabbed
                int8_t offset = 19;
                for (int l = 0; l < 20; ++l) {
                    if (buffer[l] == 0 && buffer[l + 1] != 0) {
                        offset = l;
                        break;
                    }
                }

                for (int l = 0; l < 20; ++l) {
                    if (l + offset > 19) {
                        if (noSerial){
                            tempByte = 0;
                        }else{
                            tempByte = jgLedCube::serial::readByte();
                        }

                        if (tempByte){
                            buffer[l] = tempByte;
                        }else{
                            noSerial = true;
                            buffer[l] = 0;
                        }

                    } else {
                        buffer[l] = buffer[l + offset];
                    }
                }
            }
            return foundPacket;
        }
    }
}
