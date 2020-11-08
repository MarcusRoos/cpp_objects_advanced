//
// Created by Marcus Roos on 2020-10-23.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_CONSTANTS_H
#define DT060G_CONSTANTS_H
/**
Header file for constants, not much need to be said here,
 used within the program.
 */
enum State {
    NOTASSEMBLED,
    INCOMPLETE,
    ASSEMBLED,
    READY,
    RUNNING,
    ARRIVED,
    FINISHED,
    STATEERROR
};

const int DELAYTIME = 10;
const int BUILDTIME = 30;
const int READYTIME = 10;
const int LEAVETIME = 10;
const int DISASSEMBLETIME = 20;
const int SIMMING = 1439;

#endif //DT060G_CONSTANTS_H
