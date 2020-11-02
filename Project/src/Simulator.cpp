//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#include <iomanip>
#include "Simulator.h"
#include "Events.h"


Simulator::~Simulator() {
    while (!eventQueue.empty()) {
        Event* nextEvent = eventQueue.top();
        eventQueue.pop();
        delete nextEvent;
    }
}

bool Simulator::step(int time){
    int tmpTime=0;
    tmpTime = currTime + time;
    while (currTime < tmpTime) {
        currTime++;
        while (eventQueue.top()->getTime() <= currTime) {

            Event *nextEvent = eventQueue.top();
            eventQueue.pop();
            nextEvent->processEvent();

            if (eventQueue.empty()) {
                return false;
            }
            delete nextEvent;

        }
    }
    return currTime < SIMMING;
}

void Simulator::scheduleEvent(Event* newEvent) {
    eventQueue.push(newEvent);
}