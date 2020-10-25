//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Simulator.h"
#include "constants.h"
#include "Events.h"


Simulator::~Simulator() {
    while( ! eventQueue.empty()) {
        Event* delEvent = eventQueue.top();
        eventQueue.pop();
        delEvent = NULL;
    }
}

bool Simulator::advance(int time)

{
    currTime += time;
    while(eventQueue.top()->getTime() <= currTime) {

        Event* nextEvent = eventQueue.top();
        eventQueue.pop();
        nextEvent->processEvent();

        if (eventQueue.empty())
        {
            return false;
        }
        nextEvent = NULL;
    }

    return currTime < SIMMING;

}

void Simulator::scheduleEvent(Event* newEvent) {
    eventQueue.push(newEvent);
}
