#include <gtest/gtest.h>
#include "core.h"


TEST(Core, SetBit) {
    uint8_t b = 0;
    EXPECT_EQ(0, b);
    
    jgLedCube::setBit(b, 0, 1);
    EXPECT_EQ(0x1, b);
    
    jgLedCube::setBit(b, 0, 0);
    jgLedCube::setBit(b, 1, 1);
    EXPECT_EQ(0x2, b);
    
    jgLedCube::setBit(b, 0, 1);
    jgLedCube::setBit(b, 1, 1);
    EXPECT_EQ(0x3, b);
    
    jgLedCube::setBit(b, 0, 0);
    jgLedCube::setBit(b, 1, 0);
    jgLedCube::setBit(b, 2, 1);
    EXPECT_EQ(0x4, b);
    
    jgLedCube::setBit(b, 0, 1);
    jgLedCube::setBit(b, 1, 0);
    jgLedCube::setBit(b, 2, 1);
    EXPECT_EQ(0x5, b);
    
    jgLedCube::setBit(b, 0, 0);
    jgLedCube::setBit(b, 1, 1);
    jgLedCube::setBit(b, 2, 1);
    EXPECT_EQ(0x6, b);
    
    jgLedCube::setBit(b, 0, 1);
    jgLedCube::setBit(b, 1, 1);
    jgLedCube::setBit(b, 2, 1);
    EXPECT_EQ(0x7, b);
    
    jgLedCube::setBit(b, 0, 0);
    jgLedCube::setBit(b, 1, 0);
    jgLedCube::setBit(b, 2, 0);
    jgLedCube::setBit(b, 3, 1);
    EXPECT_EQ(0x8, b);
}

TEST(Core, GetBit) {
    EXPECT_EQ(1, jgLedCube::getBit(1, 0));
    EXPECT_EQ(0, jgLedCube::getBit(1, 1));
    EXPECT_EQ(0, jgLedCube::getBit(1, 2));
    EXPECT_EQ(0, jgLedCube::getBit(1, 3));
    EXPECT_EQ(0, jgLedCube::getBit(1, 4));
    EXPECT_EQ(0, jgLedCube::getBit(1, 5));
    EXPECT_EQ(0, jgLedCube::getBit(1, 6));
    EXPECT_EQ(0, jgLedCube::getBit(1, 7));
    
    EXPECT_EQ(1, jgLedCube::getBit(5, 0));
    EXPECT_EQ(0, jgLedCube::getBit(5, 1));
    EXPECT_EQ(1, jgLedCube::getBit(5, 2));
    EXPECT_EQ(0, jgLedCube::getBit(5, 3));
    EXPECT_EQ(0, jgLedCube::getBit(5, 4));
    EXPECT_EQ(0, jgLedCube::getBit(5, 5));
    EXPECT_EQ(0, jgLedCube::getBit(5, 6));
    EXPECT_EQ(0, jgLedCube::getBit(5, 7));
    
    EXPECT_EQ(1, jgLedCube::getBit(17, 0));
    EXPECT_EQ(0, jgLedCube::getBit(17, 1));
    EXPECT_EQ(0, jgLedCube::getBit(17, 2));
    EXPECT_EQ(0, jgLedCube::getBit(17, 3));
    EXPECT_EQ(1, jgLedCube::getBit(17, 4));
    EXPECT_EQ(0, jgLedCube::getBit(17, 5));
    EXPECT_EQ(0, jgLedCube::getBit(17, 6));
    EXPECT_EQ(0, jgLedCube::getBit(17, 7));
}

//TEST(Core, SetLed) {
//    jgLedCube::clear();
//
//    jgLedCube::setLed(1, 1, 1, 15, 1);
//
//    // CHECK ALL 4 MODULATION BITS
//    uint8_t mod_bit_1 = jgLedCube::getBit(jgLedCube::dataArray[0], 1);
//    uint8_t mod_bit_2 = jgLedCube::getBit(jgLedCube::dataArray[0], 1);
//    uint8_t mod_bit_3 = jgLedCube::getBit(jgLedCube::dataArray[0], 1);
//    uint8_t mod_bit_4 = jgLedCube::getBit(jgLedCube::dataArray[0], 1);
//
//    EXPECT_EQ(mod_bit_1, 1);
//    EXPECT_EQ(mod_bit_2, 1);
//    EXPECT_EQ(mod_bit_3, 1);
//    EXPECT_EQ(mod_bit_4, 1);
//}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
