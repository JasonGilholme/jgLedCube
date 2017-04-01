//
// Created by jase on 1/04/17.
//

#ifndef JGLEDCUBE_SERIAL_H
#define JGLEDCUBE_SERIAL_H

#include <vector>
#include <string>

namespace jgLedCube {

    std::vector<std::string> listSerialPorts();

    bool isCubeOnSerialPort(std::string serialPort);



}

#endif //JGLEDCUBE_SERIAL_H
