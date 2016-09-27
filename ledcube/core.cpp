
#include <iostream>
#include <cstring>
#include "core.h"

namespace jgLedCube {

    void setBit(uint8_t &b, const uint8_t &n, const uint8_t &v){
        b ^= (-v ^ b) & (1 << n);
    }

    uint8_t getBit(uint8_t b, uint8_t n){
        return (b >> n) & 1;
    }

    // TODO: Make this support an array of values and n_channels arg instead of channel
    // Loops can be slow on AVR's so maybe some macro magic might be better instead of arrays.
    void setLed(uint8_t x, uint8_t y, uint8_t z, uint8_t value, uint8_t channel){
        // TODO: Faster way of doing this testing?
        if (channel < 1) return;
        if (channel > nChannels) return;
        if (x < 1) x = 1;
        if (x > x) x = xDimension;
        if (y < 1) y = 1;
        if (y > yDimension) y = yDimension;
        if (z < 1) z = 1;
        if (z > zDimension) z = zDimension;
        if (value < 0) value = 0;
        if (value > maxIntensity) value = maxIntensity;

        uint8_t led_id = ((z-1) * xyDimension) + (((y-1) * xDimension)) + x - 1;
        uint8_t byte_id = (led_id / 8) * channel;
        uint8_t bit_id = led_id % 8;

        // Set the 4 modulation bits
        setBit(dataArray[channel * 1 * byte_id], bit_id, getBit(value, 0));
        setBit(dataArray[channel * 2 * byte_id], bit_id, getBit(value, 1));
        setBit(dataArray[channel * 3 * byte_id], bit_id, getBit(value, 2));
        setBit(dataArray[channel * 4 * byte_id], bit_id, getBit(value, 3));
    }

    void clear(){
        memset(dataArray, 0, nArrayBytes);
    }

    void printData(){
        for(int _byte_index=0; _byte_index < nArrayBytes; _byte_index++){
            uint8_t _byte = dataArray[_byte_index];
            for(uint8_t _bit_index=0; _bit_index < 8; _bit_index++){
                std::cout
                        << _byte_index
                        << "  "
                        << (int)_bit_index
                        << "  "
                        << (int)getBit(_byte, _bit_index)
                        << std::endl;
            }
        }
    }

    void printConfig(){
        std::cout << "X_DIMENSION: "        << (int)xDimension       << std::endl;
        std::cout << "Y_DIMENSION: "        << (int)yDimension       << std::endl;
        std::cout << "Z_DIMENSION: "        << (int)zDimension       << std::endl;
        std::cout << "N_CHANNELS: "         << (int)nChannels        << std::endl;
        std::cout << "_MODULATION_BITS: "   << (int)modulationBits   << std::endl;
        std::cout << "_MAX_INTENSITY: "     << (int)maxIntensity     << std::endl;
        std::cout << "_N_ARRAY_BYTES: "     << (int)nArrayBytes      << std::endl;
    }
}
