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


class Simulator {
public:
    Simulator () : currTime (0), eventQueue() { }
    ~Simulator();
    void scheduleEvent (Event * newEvent);
    int getTime() const { return currTime; }
    void step(int time);
private:
    int currTime;
    std::priority_queue<Event*, std::vector<Event*>, EventComparison> eventQueue;
};

#endif //DT060G_SIMULATOR_H
