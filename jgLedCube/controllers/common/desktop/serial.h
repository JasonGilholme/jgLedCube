//
// Serial interaction for desktop
//

#ifndef JGLEDCUBE_SERIAL_H
#define JGLEDCUBE_SERIAL_H

#include "jgLedCube/controllers/common/desktop/typedefs.h"

namespace jgLedCube {
    serialPortList listSerialPorts();
    bool isCubeOnSerialPort(serialPort serialPort);
}

#endif //JGLEDCUBE_SERIAL_H
