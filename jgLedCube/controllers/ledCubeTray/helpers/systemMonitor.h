//
// Created by jase on 1/04/17.
//

#ifndef JGLEDCUBE_SYSTEMMONITOR_H
#define JGLEDCUBE_SYSTEMMONITOR_H

#include <vector>

struct SystemState{
    std::vector<int> cpu_tasks;
    std::vector<int> cpu_temps;
};

class SystemMonitor {

};



void readSystemState(SystemState &systemState);

#endif //JGLEDCUBE_SYSTEMMONITOR_H
