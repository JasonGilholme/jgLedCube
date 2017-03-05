//
// Created by jase on 4/03/17.
//

#include <iostream>

#include <QApplication>
#include <QWidget>

#include "jgLedCube/controllers/ledCubeTray/ui/ledCubeTray.h"

int main( int argc, char **argv )
{
    QApplication app(argc, argv);

    LedCubeTray *window = new LedCubeTray();
    window->show();

    return app.exec();
}
