#include <gtest/gtest.h>
#include <jgLedCube/defines.h>
#include <jgLedCube/serial.h>


TEST(Serial, SetLed) {
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

TEST(Serial, GetLed) {
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

TEST(Serial, GetLedReturn) {
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

TEST(Serial, GetConfig) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_getConfig(encodedCommand);

    // Decode the command
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_GET_CONFIG);
}

TEST(Serial, GetConfigReturn) {
    // Encode the command
    uint8_t encodedCommand[LED_CUBE_COMMAND_PACKET_SIZE] = {};
    jgLedCube::serial::encode_getConfigReturn(encodedCommand, 5, 6, 7, 3, 37, 245);

    // Decode the command
    uint8_t decodedArgs[3] = {};
    uint8_t decodedCommandID = jgLedCube::serial::decode_commandId(encodedCommand);
    jgLedCube::serial::decode_getConfigReturn(encodedCommand, decodedArgs);

    // Check that the decoded args match the inputs when created.
    EXPECT_EQ(decodedCommandID, LED_CUBE_CMD_GET_CONFIG_RETURN);
    EXPECT_EQ(decodedArgs[0], 5);
    EXPECT_EQ(decodedArgs[1], 6);
    EXPECT_EQ(decodedArgs[2], 7);
    EXPECT_EQ(decodedArgs[3], 3);
    EXPECT_EQ(decodedArgs[4], 37);
    EXPECT_EQ(decodedArgs[5], 245);
}
