//
// Created by jase on 1/04/17.
//

#include "Cube.h"

std::vector<Cube::CubeInfo> Cube::findCubes(std::vector<Cube::CubeInfo> cubeInfos) {
    cubeInfos.push_back(Cube::CubeInfo("/usb/port/path",
                                       "CubeName", 4, 4, 4, 3));
}

Cube::CubeInfo::CubeInfo(std::string usbPort, std::string name, int width, int height, int depth, int n_colours) :
        usbPort(usbPort),
        name(name),
        width(width),
        height(height),
        depth(depth),
        n_colours(n_colour)
{
}

Cube::CubeInfo::~CubeInfo()
{
}
