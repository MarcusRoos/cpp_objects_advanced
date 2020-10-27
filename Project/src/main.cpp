#include "SimulationProgram.h"
#include "Simulator.h"
//#include "memstat.hpp"

int main() {
    Simulator *theSim = new Simulator;
    SimulationProgram *mainmenu = new SimulationProgram(theSim);
    mainmenu->populateStation();
    mainmenu->populateMap();
    mainmenu->populateTrain();
    mainmenu->scheduleEvents();
    mainmenu->runSubMenu();
    return 0;
}
