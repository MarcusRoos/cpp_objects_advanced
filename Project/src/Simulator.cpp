//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Simulator.h"
#include "constants.h"
#include "Events.h"


Simulator::~Simulator() {
    eventQueue.empty();
}

bool Simulator::step(int time){
    currTime += time;
    while(eventQueue.top()->getTime() <= currTime) {
        Event* nextEvent = eventQueue.top();
        eventQueue.pop();
        nextEvent->processEvent();
        if (eventQueue.empty())
            return false;
    }
    return currTime < SIMMING;
}

void Simulator::scheduleEvent(Event* newEvent) {
    eventQueue.push(newEvent);
}