//
// Created by jase on 2/04/17.
//

#ifndef JGLEDCUBE_TYPEDEFS_H
#define JGLEDCUBE_TYPEDEFS_H

#include <string>
#include <vector>

namespace jgLedCube {
    typedef std::string cubeName;
    typedef std::string serialPort;
    typedef std::vector<serialPort> serialPortList;
    typedef int cubeDimensions[4];
}

#endif //JGLEDCUBE_TYPEDEFS_H
