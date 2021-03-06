//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_SIMULATOR_H
#define DT060G_SIMULATOR_H

#include <queue>
#include <vector>
#include <memory>
#include "Events.h"

/**
 Class Simulator

Handles the actual simulation, in here time will be compared, the events will
 be put in a priority queue depending on their dispatch time. It will handle
 both current time and advance the time forward once the "step" function has
 been called.
 */
class Simulator {
public:
    Simulator () : currTime (0), eventQueue() { }
    ~Simulator();
    // Add a new event to event queue.
    void scheduleEvent (Event * newEvent);
    int getTime() const { return currTime; }
    bool step(int time);
private:
    int currTime;
    /* The event queue. Always sorted with respect to the times
       for the events. The event with the 'smallest' time is always
       placed first in queue and will be processed next. */
    std::priority_queue<Event*, std::vector<Event*>, EventComparison> eventQueue;
};

#endif //DT060G_SIMULATOR_H
