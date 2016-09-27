
#include <iostream>
#include "core.h"

namespace jgLedCube {

    void setBit(char &b, const char &n, const char &v){
        b ^= (-v ^ b) & (1 << n);
    }

    char getBit(char b, char n){
        return (b >> n) & 1;
    }

    void set_led(uint8_t x, uint8_t y, uint8_t z, uint8_t value, uint8_t channel){
        // TODO: Faster way of doing this testing?
        if (channel < 0) return;
        if (channel > nChannels) return;
        if (x < 1) x = 1;
        if (x > x) x = xDimension;
        if (y < 1) y = 1;
        if (y > yDimension) y = yDimension;
        if (z < 1) z = 1;
        if (z > zDimension) z = zDimension;
        if (value < 0) value = 0;
        if (value > maxIntensity) value = maxIntensity;

        int led_id = ((z-1) * xyDimension) + (((y-1) * xDimension)) + x - 1;
        int byte_id = led_id / 8;
        int bit_id = led_id % 8;

        std::cout << "led_id:  " << led_id << std::endl;
        std::cout << "byte_id:  " << byte_id << std::endl;
        std::cout << "bit_id:  " << bit_id << std::endl;

        // Set the 4 modulation bits
//        dataArray[channel * 1 * byte_id];   // mod bit 1
//        dataArray[channel * 2 * byte_id];   // mod bit 2
//        dataArray[channel * 3 * byte_id];   // mod bit 3
//        dataArray[channel * 4 * byte_id];   // mod bit 4
    }

    void print_data(){
        for(int _byte_index=0; _byte_index < nChannels * modulationBits * nArrayBytes; _byte_index++){
            char _byte = dataArray[_byte_index];
            for(int _bit_index=0; _bit_index < 8; _bit_index++){
                std::cout
                        << _byte_index
                        << "  "
                        <<  _bit_index
                        << "  "
                        << ((_byte >> _bit_index) & 1)
                        << std::endl;
            }
        }
    }

    void print_config(){
        std::cout << "X_DIMENSION: "        << xDimension       << std::endl;
        std::cout << "Y_DIMENSION: "        << yDimension       << std::endl;
        std::cout << "Z_DIMENSION: "        << zDimension       << std::endl;
        std::cout << "N_CHANNELS: "         << nChannels        << std::endl;
        std::cout << "_MODULATION_BITS: "   << modulationBits   << std::endl;
        std::cout << "_MAX_INTENSITY: "     << maxIntensity     << std::endl;
        std::cout << "_N_ARRAY_BYTES: "     << nArrayBytes      << std::endl;
    }
}
