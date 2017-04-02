//
// Created by jase on 1/04/17.
//

#include "cubes.h"
#include "serial.h"

namespace jgLedCube {
    /* static */
    std::map<std::string, CubeFactory::_Cube*> CubeFactory::availableCubes;

    CubeFactory::_Cube *CubeFactory::getCube(serialPort _serialPort) {
        // Test if the serial port is valid and has a cube connected to it
        if (jgLedCube::isCubeOnSerialPort(_serialPort)) {
            _Cube *cube = new CubeFactory::_Cube(_serialPort);
            CubeFactory::availableCubes.insert(std::make_pair(_serialPort, cube));
            return cube;
        }
        return nullptr;
    }

    CubeFactory::_Cube::_Cube(jgLedCube::serialPort _serialPort) : serialPort(_serialPort){
        _getCubeDimensions();
        _getCubeName();
    }

    CubeFactory::_Cube::~_Cube() {
    }

    void CubeFactory::_Cube::_getCubeDimensions() {
        // Read the cube dimensions from Cube::serialPort
        cubeDimensions[0] = 8;
        cubeDimensions[1] = 8;
        cubeDimensions[2] = 8;
        cubeDimensions[3] = 3;
    }

    void CubeFactory::_Cube::_getCubeName() {
        // Read the cube name from Cube::serialPort
        cubeName = "Generic Cube Name";
    }

    void CubeFactory::_Cube::sendCommand() {
        // Send a command to cube on Cube::serialPort
    }

    CubeFactory::cubePtrList CubeFactory::findCubes() {
        CubeFactory::cubePtrList returnCubes;

        for (auto &&_serialPort : jgLedCube::listSerialPorts()) {
            _Cube* cube = getCube(_serialPort);
            if (cube != nullptr){
                returnCubes.push_back(cube);
            }
        }
        return returnCubes;
    }

    void CubeFactory::clearCubeCache() {
        for (auto &&item : availableCubes) {
            delete item.second;
        }
        availableCubes.clear();
    }
}
