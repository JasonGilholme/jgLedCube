//
// Created by jase on 1/04/17.
//

#include <iostream>
#include "systemMonitor.h"

void readSystemState(SystemState &systemState) {
    systemState.cpu_tasks.clear();
    systemState.cpu_temps.clear();
    int n_cpus = 5;
    for (int i = 0; i < n_cpus; ++i) {
        systemState.cpu_tasks.push_back(i);
    }
}
