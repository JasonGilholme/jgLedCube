//
// Created by jase on 1/04/17.
//

#include "serial.h"

jgLedCube::serialPortList jgLedCube::listSerialPorts()
{
    jgLedCube::serialPortList serialPorts;
    serialPorts.push_back("/dev/ttyUSB0");
    serialPorts.push_back("/dev/ttyUSB1");
    serialPorts.push_back("/dev/ttyUSB2");
    return serialPorts;
}

bool jgLedCube::isCubeOnSerialPort(jgLedCube::serialPort serialPort)
{
    return serialPort != "/dev/ttyUSB1";
}
