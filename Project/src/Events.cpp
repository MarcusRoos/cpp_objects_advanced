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
        time += READYTIME;
        theSim->scheduleEvent(new ReadyTrain(theSim, simmer, time, trainId));
    } else {
        time += DELAYTIME;
        theSim->scheduleEvent(new BuildTrain(theSim, simmer, time, trainId));
    }

}

void ReadyTrain::processEvent()
{
    simmer->readyTrain(trainId);
    time += LEAVETIME;
    theSim->scheduleEvent(new LeaveTrain(theSim, simmer, time, trainId));

}

void LeaveTrain::processEvent()
{
    int arrTime = simmer->dispatchTrain(trainId);
    time = arrTime;
    theSim->scheduleEvent(new ArriveTrain(theSim, simmer, time, trainId));
}

void ArriveTrain::processEvent()
{
    simmer->arriveTrain(trainId);
    time += DISASSEMBLETIME;
    theSim->scheduleEvent(new FinishTrain(theSim, simmer, time, trainId));
}

void FinishTrain::processEvent()
{
    simmer->stripTrain(trainId);

}

void EndTrain::processEvent()
{
    simmer->disassembleTrain();
}
