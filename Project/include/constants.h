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
const int BUILDTIME = 30; //note: subtracted from depTime as build happens sooner.
const int DISASSEMBLETIME = 30;
const int READYTIME = 20;
const int LEAVETIME = 10;
const int SIMMINGTIME = 600;

#endif //DT060G_CONSTANTS_H
