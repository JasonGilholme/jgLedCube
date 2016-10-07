
#ifndef JGLEDCUBE_EMBEDDED_DEFINES_H
#define JGLEDCUBE_EMBEDDED_DEFINES_H

#define LED_CUBE_XY_DIMENSION LED_CUBE_X_DIMENSION * LED_CUBE_Y_DIMENSION
#define LED_CUBE_XYZ_DIMENSION LED_CUBE_XY_DIMENSION * LED_CUBE_Y_DIMENSION

#define LED_CUBE_MODULATION_BITS 4
#define LED_CUBE_MAX_INTENSITY 15
#define LED_CUBE_MODULATION_BLOCK_SIZE LED_CUBE_XYZ_DIMENSION / 8.0 * LED_CUBE_N_CHANNELS
#define LED_CUBE_MODULATION_BLOCK_SIZE_X2 LED_CUBE_MODULATION_BLOCK_SIZE * 2
#define LED_CUBE_MODULATION_BLOCK_SIZE_X3 LED_CUBE_MODULATION_BLOCK_SIZE * 3

#define LED_CUBE_DATA_ARRAY_SIZE LED_CUBE_MODULATION_BLOCK_SIZE * LED_CUBE_MODULATION_BITS
#define LED_CUBE_LUT_SIZE LED_CUBE_XY_DIMENSION * LED_CUBE_N_CHANNELS

#endif
