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
    Simulator () : eventQueue(), currTime(0) { }
    ~Simulator();
    void scheduleEvent (std::shared_ptr<Event> newEvent);
    int getTime() const { return currTime; }
    bool advance(int time);

private:
    int currTime;
    std::priority_queue<std::shared_ptr<Event>, std::vector<std::shared_ptr<Event>>, EventComparison> eventQueue;
};

#endif //DT060G_SIMULATOR_H
