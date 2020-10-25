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
        std::shared_ptr<Event> delEvent = eventQueue.top();
        eventQueue.pop();
        delEvent.reset();
    }
}

bool Simulator::advance(int time)

{
    currTime += time;

    while(eventQueue.top()->getTime() <= currTime) {

        std::shared_ptr<Event> nextEvent = eventQueue.top();
        eventQueue.pop();
        nextEvent->processEvent();

        if (eventQueue.empty())
        {
            return false;
        }
        nextEvent.reset();
    }

    return currTime < SIMMING;

}

void Simulator::scheduleEvent(std::shared_ptr<Event> newEvent) {
    eventQueue.push(newEvent);
}
