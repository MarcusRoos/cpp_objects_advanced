//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Events.h"
#include "SimulationProgram.h"
#include "Simulator.h"

//Processes the event to build a train
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

//Processes the event to sign a train as ready
void ReadyTrain::processEvent()
{
    time += LEAVETIME;
    simmer->readyTrain(trainId);
    theSim->scheduleEvent(new LeaveTrain(theSim, simmer, time, trainId));
}

//Processes the event to dispatch a train
void LeaveTrain::processEvent()
{
    time = simmer->dispatchTrain(trainId);
    theSim->scheduleEvent(new ArriveTrain(theSim, simmer, time, trainId));
}

//Processes the event to sign a train as arrived
void ArriveTrain::processEvent()
{
    time += DISASSEMBLETIME;
    theSim->scheduleEvent(new FinishTrain(theSim, simmer, time, trainId));
    simmer->arriveTrain(trainId);
}

//Processes the event to sign a train when complete and at end destination
void FinishTrain::processEvent()
{
    simmer->EndTrain(trainId);
}
