#include <gtest/gtest.h>
#include <jgLedCube/defines.h>
#include <jgLedCube/serial.h>
#include <jgLedCube/core.h>


TEST(Serial, EncodeSetLed) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_setLed(encodedCommand, 2, 4, 6, 15, 13, 9);

    // Decode the command
    uint8_t decodedArgs[6] = {};
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);
    jgLedCube::serial::decode_setLed(encodedCommand, decodedArgs);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_SET_LED);
    EXPECT_EQ(decodedArgs[0], 2);
    EXPECT_EQ(decodedArgs[1], 4);
    EXPECT_EQ(decodedArgs[2], 6);
    EXPECT_EQ(decodedArgs[3], 15);
    EXPECT_EQ(decodedArgs[4], 13);
    EXPECT_EQ(decodedArgs[5], 9);
}

TEST(Serial, EncodeGetLed) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_getLed(encodedCommand, 3, 6, 9);

    // Decode the command
    uint8_t decodedArgs[3] = {};
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);
    jgLedCube::serial::decode_getLed(encodedCommand, decodedArgs);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_GET_LED);
    EXPECT_EQ(decodedArgs[0], 3);
    EXPECT_EQ(decodedArgs[1], 6);
    EXPECT_EQ(decodedArgs[2], 9);
}

TEST(Serial, EncodeGetLedReturn) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_getLedReturn(encodedCommand, 14, 12, 13);

    // Decode the command
    uint8_t decodedArgs[3] = {};
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);
    jgLedCube::serial::decode_getLedReturn(encodedCommand, decodedArgs);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_GET_LED_RETURN);
    EXPECT_EQ(decodedArgs[0], 14);
    EXPECT_EQ(decodedArgs[1], 12);
    EXPECT_EQ(decodedArgs[2], 13);
}

TEST(Serial, EncodeGetConfig) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_getConfig(encodedCommand);

    // Decode the command
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_GET_CONFIG);
}

TEST(Serial, EncodeGetConfigReturn) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_getConfigReturn(encodedCommand);

    // Decode the command
    uint8_t decodedArgs[3] = {};
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);
    jgLedCube::serial::decode_getConfigReturn(encodedCommand, decodedArgs);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_GET_CONFIG_RETURN);
    EXPECT_EQ(decodedArgs[0], LED_CUBE_X_DIMENSION);
    EXPECT_EQ(decodedArgs[1], LED_CUBE_Y_DIMENSION);
    EXPECT_EQ(decodedArgs[2], LED_CUBE_Z_DIMENSION);
    EXPECT_EQ(decodedArgs[3], LED_CUBE_N_CHANNELS);
    EXPECT_EQ(decodedArgs[4], LED_CUBE_VERSION);
    EXPECT_EQ(decodedArgs[5], LED_CUBE_UID);
}

TEST(Serial, EncodeClear) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_clear(encodedCommand);

    // Decode the command
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_CLEAR);
}

TEST(Serial, ProcessSetLed) {
    jgLedCube::core::clear();

    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_setLed(encodedCommand, 2, 2, 2, 15, 13, 9);

    jgLedCube::serial::processCommand(encodedCommand);

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    for (uint8_t z=1; z <= LED_CUBE_Z_DIMENSION; z++){
        for (uint8_t y=1; y <= LED_CUBE_Y_DIMENSION; y++){
            for (uint8_t x=1; x <= LED_CUBE_X_DIMENSION; x++){
                jgLedCube::core::getLed(x, y, z, r, g, b);
                if (x == 2 && y == 2 && z == 2){
                    EXPECT_EQ(r, 15);
                    EXPECT_EQ(g, 13);
                    EXPECT_EQ(b, 9);
                }else{
                    EXPECT_EQ(r, 0);
                    EXPECT_EQ(g, 0);
                    EXPECT_EQ(b, 0);
                }
            }
        }
    }
}

TEST(Serial, ProcessClear) {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    for (uint8_t z=1; z <= LED_CUBE_Z_DIMENSION; z++){
        for (uint8_t y=1; y <= LED_CUBE_Y_DIMENSION; y++){
            for (uint8_t x=1; x <= LED_CUBE_X_DIMENSION; x++){
                jgLedCube::core::setLed(x, y, z, 15, 15, 15);
            }
        }
    }

    for (uint8_t z=1; z <= LED_CUBE_Z_DIMENSION; z++){
        for (uint8_t y=1; y <= LED_CUBE_Y_DIMENSION; y++){
            for (uint8_t x=1; x <= LED_CUBE_X_DIMENSION; x++){
                jgLedCube::core::getLed(x, y, z, r, g, b);
                EXPECT_EQ(r, 15);
                EXPECT_EQ(g, 15);
                EXPECT_EQ(b, 15);
            }
        }
    }

    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_clear(encodedCommand);

    jgLedCube::serial::processCommand(encodedCommand);

    for (uint8_t z=1; z <= LED_CUBE_Z_DIMENSION; z++){
        for (uint8_t y=1; y <= LED_CUBE_Y_DIMENSION; y++){
            for (uint8_t x=1; x <= LED_CUBE_X_DIMENSION; x++){
                jgLedCube::core::getLed(x, y, z, r, g, b);
                EXPECT_EQ(r, 0);
                EXPECT_EQ(g, 0);
                EXPECT_EQ(b, 0);
            }
        }
    }
}
