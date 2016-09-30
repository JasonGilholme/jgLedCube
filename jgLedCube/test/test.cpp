#include <gtest/gtest.h>
#include <jgLedCube/core.h>


TEST(Core, SetBit) {
    uint8_t b = 0;
    EXPECT_EQ(0, b);
    
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

TEST(Core, SetLed) {
    jgLedCube::core::clear();

    jgLedCube::core::setLed(1, 1, 1, 15, 15, 15);

    // With the test cube spec being 2x2x2 with 3 channels,
    // we have a 3 byte modulation block size.
    uint8_t mod_bit_1_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[0], 0);
    uint8_t mod_bit_1_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[0], 1);
    uint8_t mod_bit_1_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[0], 2);

    uint8_t mod_bit_2_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[3], 0);
    uint8_t mod_bit_2_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[3], 1);
    uint8_t mod_bit_2_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[3], 2);

    uint8_t mod_bit_3_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[6], 0);
    uint8_t mod_bit_3_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[6], 1);
    uint8_t mod_bit_3_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[6], 2);

    uint8_t mod_bit_4_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[9], 0);
    uint8_t mod_bit_4_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[9], 1);
    uint8_t mod_bit_4_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[9], 2);

    EXPECT_EQ(mod_bit_1_R, 1);
    EXPECT_EQ(mod_bit_1_G, 1);
    EXPECT_EQ(mod_bit_1_B, 1);

    EXPECT_EQ(mod_bit_2_R, 1);
    EXPECT_EQ(mod_bit_2_G, 1);
    EXPECT_EQ(mod_bit_2_B, 1);

    EXPECT_EQ(mod_bit_3_R, 1);
    EXPECT_EQ(mod_bit_3_G, 1);
    EXPECT_EQ(mod_bit_3_B, 1);

    EXPECT_EQ(mod_bit_4_R, 1);
    EXPECT_EQ(mod_bit_4_G, 1);
    EXPECT_EQ(mod_bit_4_B, 1);

}


int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

    jgLedCube::core::printConfig();
}
