//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_CONSTANTS_H
#define DT060G_CONSTANTS_H

enum State {
    UNASSMEBLED,
    NOT_READY,
    INCOMPLETE,
    READY,
    RUNNING,
    ARRIVED,
    FINISHED
};

const int TICK = 10;
const int DELAYTIME = 10;
const int BUILDTIME = 20;
const int READYTIME = 20;
const int LEAVETIME = 10;
const int DISASSEMBLETIME = 30;
const int SIMMING = 600;

#endif //DT060G_CONSTANTS_H
