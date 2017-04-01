//
// Created by jase on 1/04/17.
//

#ifndef JGLEDCUBE_CUBE_H
#define JGLEDCUBE_CUBE_H

#include <string>
#include <vector>


class Cube{

public:
    static std::vector<CubeInfo> findCubes(std::vector<Cube::CubeInfo> cubeInfos);

    class CubeInfo {
    public:
        CubeInfo(std::string usdPort,
                 std::string name,
                 int width,
                 int height,
                 int depth,
                 int n_colours);
        virtual ~CubeInfo();
        std::string usbPort;
        std::string name;
        int width;
        int height;
        int depth;
        int n_colours;

    };

};

#endif //JGLEDCUBE_CUBE_H
