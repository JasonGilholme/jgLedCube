//
// Created by jase on 1/04/17.
//

#ifndef JGLEDCUBE_CUBE_H
#define JGLEDCUBE_CUBE_H

#include <string>
#include <vector>

namespace jgLedCube {

    typedef std::vector<Cube> cubeList;

    cubeList findCubes();

    class Cube {
    public:
        Cube();
        ~Cube();

        std::string name;
        std::string portName;

        int width;
        int height;
        int depth;
        int n_colours;

    };
}

#endif //JGLEDCUBE_CUBE_H
