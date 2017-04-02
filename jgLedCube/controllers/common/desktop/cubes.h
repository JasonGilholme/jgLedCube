//
// Discover and cache info regarding connected cubes
//

#ifndef JGLEDCUBE_CUBE_H
#define JGLEDCUBE_CUBE_H

#include <map>
#include "jgLedCube/controllers/common/desktop/typedefs.h"

namespace jgLedCube {

    class CubeFactory {
    private:
        class _Cube {
        private:
            void _getCubeDimensions();
            void _getCubeName();

        public:
            _Cube(jgLedCube::serialPort _serialPort);
            ~_Cube();

            void sendCommand();
            jgLedCube::cubeName cubeName;
            jgLedCube::serialPort serialPort;
            jgLedCube::cubeDimensions cubeDimensions;
        };

    public:
        typedef _Cube* cubePtr;
        typedef std::vector<cubePtr> cubePtrList;
        typedef std::map<serialPort, _Cube*> cubeMap;

        /* Cube Cache */
        static cubeMap availableCubes;

        static _Cube *getCube(serialPort serialPort);
        static cubePtrList findCubes();
        static void clearCubeCache();
    };
}

#endif //JGLEDCUBE_CUBE_H
