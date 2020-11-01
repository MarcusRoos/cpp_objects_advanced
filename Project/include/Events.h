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

// Forward declarations
class Simulator;
class SimulationProgram;

class Event {
public:
    Event (unsigned int t) : time(t) { }
    ~Event() = default;
    virtual void processEvent()=0;
    unsigned int getTime() const {return time;}

protected:
    unsigned int time;
};



class EventComparison {
public:
    bool operator() (Event * left, Event * right) {
        return left->getTime() > right->getTime();
    }
};

//--- Derived Event-classes ----------------------------------------------------

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


class EndTrain : public Event {
public:
    EndTrain (Simulator *sim, SimulationProgram *simmer, int time, int trainId)
            : Event(time),theSim(sim),simmer(simmer) { }

    virtual void processEvent();

protected:
    Simulator* theSim;
    SimulationProgram* simmer;
};

#endif //DT060G_EVENTS_H
