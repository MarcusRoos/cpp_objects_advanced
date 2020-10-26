//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Events.h"
#include "SimulationProgram.h"
#include "Simulator.h"


void BuildTrain::processEvent()
{
    if (simmer->tryBuild(trainId))
    {
        theSim->scheduleEvent(new ReadyTrain(theSim, simmer, time, trainId));
        time += READYTIME;
    } else {
        theSim->scheduleEvent(new BuildTrain(theSim, simmer, time, trainId));
        time += DELAYTIME;
    }

}

void ReadyTrain::processEvent()
{
    simmer->readyTrain(trainId);
    theSim->scheduleEvent(new LeaveTrain(theSim, simmer, time, trainId));
    time += LEAVETIME;
}

void LeaveTrain::processEvent()
{
    theSim->scheduleEvent(new ArriveTrain(theSim, simmer, time, trainId));
    int arrTime = simmer->dispatchTrain(trainId);
    time = arrTime;
}

void ArriveTrain::processEvent()
{
    theSim->scheduleEvent(new FinishTrain(theSim, simmer, time, trainId));
    simmer->arriveTrain(trainId);
    time += DISASSEMBLETIME;
}

void FinishTrain::processEvent()
{
    simmer->EndTrain(trainId);
}

void EndTrain::processEvent()
{
    simmer->endSimulation();
}
