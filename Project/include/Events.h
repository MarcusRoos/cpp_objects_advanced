//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_EVENTS_H
#define DT060G_EVENTS_H
#include <memory>
#include "constants.h"
#include "train.h"

/**
 Class Events

Handles the different events and states for the overlying program. These events
 will be called both by the simulator and the main program to handle the
 different states a train may be in, as well as to build and disassemble the train.
 */

// Forward declarations
class Simulator;
class SimulationProgram;

// Base class
class Event {
public:
    // Constructor requires time of event
    Event (unsigned int t) : time(t) { }
    virtual ~Event() = default;

    // Process event by invoking this method
    virtual void processEvent()=0;

    // Get time for this event
    unsigned int getTime() const {
        return time;
    }

protected:
    // Time for this event
    unsigned int time;
};

// Used to compare to Events with respect to time
class EventComparison {
public:
    bool operator() (Event * left, Event * right) {
        return left->getTime() > right->getTime();
    }
};

//--- Derived Event-classes ----------------------------------------------------
// Takes care of building a train
class BuildTrain : public Event {
public:
    BuildTrain (Simulator *sim, SimulationProgram *simmer, int time, int trainId)
            : Event(time),theSim(sim),simmer(simmer),trainId(trainId) {}

    virtual void processEvent();

protected:
    Simulator* theSim;
    SimulationProgram* simmer;
    int trainId;
};

//Takes care of signing a train as ready to leave
class ReadyTrain : public Event {
public:
    ReadyTrain (Simulator *sim, SimulationProgram *simmer, int time, int trainId)
            : Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    Simulator* theSim;
    SimulationProgram* simmer;
    int trainId;
};

//Takes care of signing a train as dispatched
class LeaveTrain : public Event {
public:
    LeaveTrain(Simulator *sim, SimulationProgram *simmer, int time, int trainId)
            :Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    Simulator* theSim;
    SimulationProgram* simmer;
    int trainId;
};

//Takes care of signing a train as arrived
class ArriveTrain : public Event {
public:
    ArriveTrain(Simulator *sim, SimulationProgram *simmer, int time, int trainId)
            :Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    Simulator* theSim;
    SimulationProgram* simmer;
    int trainId;
};

//Takes care of signing a train as finished
class FinishTrain : public Event {
public:
    FinishTrain (Simulator *sim, SimulationProgram *simmer, int time, int trainId)
            :Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    Simulator* theSim;
    SimulationProgram* simmer;
    int trainId;
};

#endif //DT060G_EVENTS_H
