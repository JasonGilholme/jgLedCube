//
// Created by jase on 4/03/17.
//

#ifndef JGLEDCUBE_LEDCUBETRAY_H
#define JGLEDCUBE_LEDCUBETRAY_H

#include <QtWidgets>



namespace Ui {
    class ledCubeTrayUi;
    class systemMonitorUi;
}

class LedCubeTray : public QWidget
{
    Q_OBJECT

public:
    LedCubeTray(QWidget *parent = 0);
    virtual ~LedCubeTray();

private:
    Ui::ledCubeTrayUi *ui;
    Ui::systemMonitorUi *sysMonUi;



    void setupInterface();
};

#endif //JGLEDCUBE_LEDCUBETRAY_H
