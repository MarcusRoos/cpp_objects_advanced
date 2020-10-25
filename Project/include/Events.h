//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_EVENTS_H
#define DT060G_EVENTS_H
#include <memory>
#include "constants.h"

// Forward declarations
class Simulator;
class SimulationProgram;

class Event {
public:
    Event (unsigned int t) : time(t) { }
    ~Event() { }
    virtual void processEvent()=0;
    unsigned int getTime() const {
        return time;
    }

protected:
    unsigned int time;
};



class EventComparison {
public:
    bool operator() (std::shared_ptr<Event> left, std::shared_ptr<Event> right) {
        return left->getTime() > right->getTime();
    }
};

//--- Derived Event-classes ----------------------------------------------------

class BuildTrain : public Event {
public:
    BuildTrain (std::shared_ptr<Simulator> sim, std::shared_ptr<SimulationProgram> simmer, int time, int trainId)
            : Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    int trainId;
    std::shared_ptr<Simulator> theSim;
    std::shared_ptr<SimulationProgram> simmer;
};

class ReadyTrain : public Event {
public:
    ReadyTrain (std::shared_ptr<Simulator> sim, std::shared_ptr<SimulationProgram> simmer, int time, int trainId)
            : Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    int trainId;
    std::shared_ptr<Simulator> theSim;
    std::shared_ptr<SimulationProgram> simmer;
};



class LeaveTrain : public Event {
public:
    LeaveTrain(std::shared_ptr<Simulator> sim, std::shared_ptr<SimulationProgram> simmer, int time, int trainId )
            :Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    int trainId;
    std::shared_ptr<Simulator> theSim;
    std::shared_ptr<SimulationProgram> simmer;
};



class ArriveTrain : public Event {
public:
    ArriveTrain(std::shared_ptr<Simulator> sim, std::shared_ptr<SimulationProgram> simmer, int time, int trainId )
            :Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    int trainId;
    std::shared_ptr<Simulator> theSim;
    std::shared_ptr<SimulationProgram> simmer;
};


class FinishTrain : public Event {
public:
    FinishTrain (std::shared_ptr<Simulator> sim, std::shared_ptr<SimulationProgram> simmer, int time, int trainId)
            :Event(time),theSim(sim),simmer(simmer),trainId(trainId) { }

    virtual void processEvent();

protected:
    int trainId;
    std::shared_ptr<Simulator> theSim;
    std::shared_ptr<SimulationProgram> simmer;
};


class EndTrain : public Event {
public:
    EndTrain (std::shared_ptr<Simulator> sim, std::shared_ptr<SimulationProgram> simmer, int time)
            : Event(time),theSim(sim),simmer(simmer) { }

    virtual void processEvent();

protected:
    std::shared_ptr<Simulator> theSim;
    std::shared_ptr<SimulationProgram> simmer;
};

#endif //DT060G_EVENTS_H
