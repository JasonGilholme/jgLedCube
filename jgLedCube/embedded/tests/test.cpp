
#include <gtest/gtest.h>
#include <jgLedCube/embedded/core.h>

int main(int argc, char **argv) {
    jgLedCube::core::printConfig();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
