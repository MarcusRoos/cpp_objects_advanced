#include "SimulationProgram.h"
#include "Simulator.h"
//#include "memstat.hpp"

int main() {
    Simulator *theSim = new Simulator;
    SimulationProgram *mainmenu = new SimulationProgram(theSim);
    mainmenu->runSubMenu();
    return 0;
}
