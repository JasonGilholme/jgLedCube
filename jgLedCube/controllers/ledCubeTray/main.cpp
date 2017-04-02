//
// Created by jase on 4/03/17.
//

//#include <QApplication>
//#include <QWidget>
//#include <iostream>

#include "jgLedCube/controllers/ledCubeTray/ui/ledCubeTray.h"
#include "jgLedCube/controllers/common/desktop/cubes.h"

//#include "jgLedCube/controllers/common/desktop/"

int main( int argc, char **argv )
{

//    jgLedCube::CubeFactory::TestMap.insert(std::make_pair<std::string, std::string>("test", "value"));

    QApplication app(argc, argv);
    LedCubeTray *window = new LedCubeTray();
    window->show();
    return app.exec();
}
