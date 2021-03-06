
#ifndef JGLEDCUBE_COMMON_DEFINES_H
#define JGLEDCUBE_COMMON_DEFINES_H

#define LED_CUBE_COMMAND_PACKET_SIZE 4
#define LED_CUBE_TRANSPORT_PACKET_SIZE LED_CUBE_COMMAND_PACKET_SIZE + 4

#define LED_CUBE_SERIAL_BAUD 115200
#ifndef LED_CUBE_IN_SERIAL_PORT
#define LED_CUBE_IN_SERIAL_PORT "/dev/ttyUSB"
#endif
#ifndef LED_CUBE_OUT_SERIAL_PORT
#define LED_CUBE_OUT_SERIAL_PORT "/dev/ttyUSB0"
#endif

/// ++++++++++ COMMANDS ++++++++++ ///
#define LED_CUBE_CMD_SET_LED 1
#define LED_CUBE_CMD_SET_MODE 2
#define LED_CUBE_CMD_GET_CONFIG 3
#define LED_CUBE_CMD_GET_LED 4
#define LED_CUBE_CMD_GET_MODES 5
#define LED_CUBE_CMD_GET_MODE 6
#define LED_CUBE_CMD_GET_LED_RETURN 7
#define LED_CUBE_CMD_GET_CONFIG_RETURN 8
#define LED_CUBE_CMD_GET_MODES_RETURN 9
#define LED_CUBE_CMD_GET_MODE_RETURN 10
#define LED_CUBE_CMD_CLEAR 11

/// ++++++++++ MODES ++++++++++ ///
#define LED_CUBE_MODE_SERIAL_LISTEN 100

#endif //JGLEDCUBE_COMMON_DEFINES_H
