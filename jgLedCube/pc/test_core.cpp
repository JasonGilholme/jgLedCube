#include <gtest/gtest.h>
#include <jgLedCube/core.h>


TEST(Core, SetBit) {
    uint8_t b = 0;

    jgLedCube::core::setBit(b, 0, 1);
    EXPECT_EQ(0x1, b);
    
    jgLedCube::core::setBit(b, 0, 0);
    jgLedCube::core::setBit(b, 1, 1);
    EXPECT_EQ(0x2, b);
    
    jgLedCube::core::setBit(b, 0, 1);
    jgLedCube::core::setBit(b, 1, 1);
    EXPECT_EQ(0x3, b);
    
    jgLedCube::core::setBit(b, 0, 0);
    jgLedCube::core::setBit(b, 1, 0);
    jgLedCube::core::setBit(b, 2, 1);
    EXPECT_EQ(0x4, b);
    
    jgLedCube::core::setBit(b, 0, 1);
    jgLedCube::core::setBit(b, 1, 0);
    jgLedCube::core::setBit(b, 2, 1);
    EXPECT_EQ(0x5, b);
    
    jgLedCube::core::setBit(b, 0, 0);
    jgLedCube::core::setBit(b, 1, 1);
    jgLedCube::core::setBit(b, 2, 1);
    EXPECT_EQ(0x6, b);
    
    jgLedCube::core::setBit(b, 0, 1);
    jgLedCube::core::setBit(b, 1, 1);
    jgLedCube::core::setBit(b, 2, 1);
    EXPECT_EQ(0x7, b);
    
    jgLedCube::core::setBit(b, 0, 0);
    jgLedCube::core::setBit(b, 1, 0);
    jgLedCube::core::setBit(b, 2, 0);
    jgLedCube::core::setBit(b, 3, 1);
    EXPECT_EQ(0x8, b);
}

TEST(Core, GetBit) {
    EXPECT_EQ(1, jgLedCube::core::getBit(1, 0));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 1));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 2));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 3));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 4));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 5));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 6));
    EXPECT_EQ(0, jgLedCube::core::getBit(1, 7));
    
    EXPECT_EQ(1, jgLedCube::core::getBit(5, 0));
    EXPECT_EQ(0, jgLedCube::core::getBit(5, 1));
    EXPECT_EQ(1, jgLedCube::core::getBit(5, 2));
    EXPECT_EQ(0, jgLedCube::core::getBit(5, 3));
    EXPECT_EQ(0, jgLedCube::core::getBit(5, 4));
    EXPECT_EQ(0, jgLedCube::core::getBit(5, 5));
    EXPECT_EQ(0, jgLedCube::core::getBit(5, 6));
    EXPECT_EQ(0, jgLedCube::core::getBit(5, 7));
    
    EXPECT_EQ(1, jgLedCube::core::getBit(17, 0));
    EXPECT_EQ(0, jgLedCube::core::getBit(17, 1));
    EXPECT_EQ(0, jgLedCube::core::getBit(17, 2));
    EXPECT_EQ(0, jgLedCube::core::getBit(17, 3));
    EXPECT_EQ(1, jgLedCube::core::getBit(17, 4));
    EXPECT_EQ(0, jgLedCube::core::getBit(17, 5));
    EXPECT_EQ(0, jgLedCube::core::getBit(17, 6));
    EXPECT_EQ(0, jgLedCube::core::getBit(17, 7));
}

TEST(Core, Clear) {
    // Flood the array
    for (uint8_t z=1; z <= LED_CUBE_Z_DIMENSION; z++){
        for (uint8_t y=1; y <= LED_CUBE_Y_DIMENSION; y++){
            for (uint8_t x=1; x <= LED_CUBE_X_DIMENSION; x++){
                jgLedCube::core::setLed(x, y, z, 15, 15, 15);
            }
        }
    }

    // Make sure they're all 1
    for (uint16_t i = 0; i < LED_CUBE_DATA_ARRAY_SIZE; i++){
        for (uint8_t j=0; j < 8; j++){
            uint8_t array_bit = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], j);
            EXPECT_EQ(array_bit, 1);
        }
    }

    // Clear it
    jgLedCube::core::clear();

    // Make sure they're all 0
    for (uint16_t i = 0; i < LED_CUBE_DATA_ARRAY_SIZE; i++){
        for (uint8_t j=0; j < 8; j++){
            uint8_t array_bit = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], j);
            EXPECT_EQ(array_bit, 0);
        }
    }
}

TEST(Core, SetLed) {
    jgLedCube::core::clear();

    // With these co-ords, the first 3 bits of the first byte in each modulation
    // block should be 1, the rest should be zero.
    jgLedCube::core::setLed(1, 1, 1, 15, 15, 15);
    for (uint16_t i = 0; i < LED_CUBE_DATA_ARRAY_SIZE; i += LED_CUBE_MODULATION_BLOCK_SIZE){
        for (uint8_t j=0; j < 8; j++){
            uint8_t array_bit = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], j);
            EXPECT_EQ(array_bit, j < 3 ? 1 : 0);
        }
    }
}

TEST(Core, GetLedLoop) {
    jgLedCube::core::clear();

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    for (uint8_t z=1; z <= LED_CUBE_Z_DIMENSION; z++){
        for (uint8_t y=1; y <= LED_CUBE_Y_DIMENSION; y++){
            for (uint8_t x=1; x <= LED_CUBE_X_DIMENSION; x++){
                jgLedCube::core::clear();
                jgLedCube::core::setLed(x, y, z, 14, 9, 3);
                jgLedCube::core::getLed(x, y, z, r, g, b);
                EXPECT_EQ(r, 14);
                EXPECT_EQ(g, 9);
                EXPECT_EQ(b, 3);
            }
        }
    }
}

TEST(Core, GetLed) {
    jgLedCube::core::clear();

    jgLedCube::core::setLed(1, 1, 1, 1, 2, 3);
    jgLedCube::core::setLed(2, 2, 2, 4, 5, 6);
    jgLedCube::core::setLed(3, 3, 3, 7, 8, 9);
    jgLedCube::core::setLed(4, 4, 4, 10, 11, 12);

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    jgLedCube::core::getLed(1, 1, 1, r, g, b);
    EXPECT_EQ(r, 1);
    EXPECT_EQ(g, 2);
    EXPECT_EQ(b, 3);

    jgLedCube::core::getLed(2, 2, 2, r, g, b);
    EXPECT_EQ(r, 4);
    EXPECT_EQ(g, 5);
    EXPECT_EQ(b, 6);

    jgLedCube::core::getLed(3, 3, 3, r, g, b);
    EXPECT_EQ(r, 7);
    EXPECT_EQ(g, 8);
    EXPECT_EQ(b, 9);

    jgLedCube::core::getLed(4, 4, 4, r, g, b);
    EXPECT_EQ(r, 10);
    EXPECT_EQ(g, 11);
    EXPECT_EQ(b, 12);
}

TEST(Core, Modulation) {
    // TEST THAT THE RIGHT MODULATION BITS ARE BEING SET
    jgLedCube::core::clear();

    // With these co-ords, the first three bytes of each modulation bit should look like this.
    // mod_block  1, 2, 3, 4
    // r = 2  -> [0, 1, 0, 0]  bit 1 in first byte
    // g = 4  -> [0, 0, 1, 0]  bit 2 in first byte
    // b = 8  -> [0, 0, 0, 1]  bit 3 in first byte
    jgLedCube::core::setLed(1, 1, 1, 2, 4, 8);

    for (uint16_t i = 0; i < LED_CUBE_DATA_ARRAY_SIZE; i++){
        for (uint8_t j=0; j < 8; j++) {
            uint8_t array_bit = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], j);

            switch (i) {
                case (uint16_t)(LED_CUBE_MODULATION_BLOCK_SIZE):
                    EXPECT_EQ(array_bit, j == 0 ? 1 : 0);
                    break;
                case (uint16_t)(LED_CUBE_MODULATION_BLOCK_SIZE * 2):
                    EXPECT_EQ(array_bit, j == 1 ? 1 : 0);
                    break;
                case (uint16_t)(LED_CUBE_MODULATION_BLOCK_SIZE * 3):
                    EXPECT_EQ(array_bit, j == 2 ? 1 : 0);
                    break;
                default :
                    EXPECT_EQ(array_bit, 0);
            }
        }
    }
}
