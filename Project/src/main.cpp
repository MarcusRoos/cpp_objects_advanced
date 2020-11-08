#include "SimulationProgram.h"
#include "Simulator.h"
#include "memstat.hpp"

int main() {
    auto *theSim = new Simulator;
    auto *mainmenu = new SimulationProgram(theSim);
    mainmenu->populateStation();
    mainmenu->populateMap();
    mainmenu->populateTrain();
    mainmenu->scheduleEvents();
    mainmenu->runSubMenu();
    delete theSim;
    delete mainmenu;
    return 0;
}
