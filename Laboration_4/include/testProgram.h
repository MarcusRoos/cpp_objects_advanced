//
// Created by Marcus Roos on 2020-10-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TESTPROGRAM_H
#define DT060G_TESTPROGRAM_H

#include "Menu.h"

class testProgram {
private:
    // Creates an object of menu, to be able to print the menu and
    // it's items.
    Menu menu;
    // Creates an object of bank, to be able to access the bank and
    // it's items.
public:
    testProgram();
    void run();
};

#endif //DT060G_TESTPROGRAM_H
