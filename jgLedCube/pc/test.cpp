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

//    std::cout << &jgLedCube::core::dataArray << std::endl;


    std::cout << &jgLedCube::core::dataArray << std::endl;

    jgLedCube::core::printData();

//    jgLedCube::core::clear();
//
//    jgLedCube::core::setLed(1, 1, 1, 15, 15, 15);
//
//    // With the test cube spec being 4x4x4 with 3 channels,
//    // we have a 24 byte modulation block size.
//    int modBlockSize = 24;
//    int i = 0;
//
//    uint8_t zero = 0;
//    uint8_t one = 1;
//    uint8_t two = 2;
//
//
//    std::cout << &jgLedCube::core::dataArray << std::endl;
//
//    uint8_t b = jgLedCube::core::dataArray[i];
//
//    uint8_t mod_bit_1_R = jgLedCube::core::getBit(b, zero);
//    uint8_t mod_bit_1_G = jgLedCube::core::getBit(b, one);
//    uint8_t mod_bit_1_B = jgLedCube::core::getBit(b, two);

//    i += modBlockSize;
//
//    uint8_t mod_bit_2_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 0);
//    uint8_t mod_bit_2_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 1);
//    uint8_t mod_bit_2_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 2);
//
//    i += modBlockSize;
//
//    uint8_t mod_bit_3_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 0);
//    uint8_t mod_bit_3_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 1);
//    uint8_t mod_bit_3_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 2);
//
//    i += modBlockSize;
//
//    uint8_t mod_bit_4_R = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 0);
//    uint8_t mod_bit_4_G = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 1);
//    uint8_t mod_bit_4_B = jgLedCube::core::getBit(jgLedCube::core::dataArray[i], 2);

//    jgLedCube::core::printData();
//
//    EXPECT_EQ(mod_bit_1_R, 1);
//    EXPECT_EQ(mod_bit_1_G, 1);
//    EXPECT_EQ(mod_bit_1_B, 1);

//    EXPECT_EQ(mod_bit_2_R, 1);
//    EXPECT_EQ(mod_bit_2_G, 1);
//    EXPECT_EQ(mod_bit_2_B, 1);
//
//    EXPECT_EQ(mod_bit_3_R, 1);
//    EXPECT_EQ(mod_bit_3_G, 1);
//    EXPECT_EQ(mod_bit_3_B, 1);
//
//    EXPECT_EQ(mod_bit_4_R, 1);
//    EXPECT_EQ(mod_bit_4_G, 1);
//    EXPECT_EQ(mod_bit_4_B, 1);

}


int main(int argc, char **argv) {
    jgLedCube::core::printConfig();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();


}
