//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TESTPROGRAM_H
#define DT060G_TESTPROGRAM_H
#include "Menu.h"
#include <fstream>
#include <vector>
/**
 Class testApp

 The testApp will handle the menu options and allow user input, it will
 handle the communication between the user and the underlying classes.
 From here the user will be able to call different functions which will
 handle different tasks. A queue need to be created by using the first
 alternative before any of the other options open up, exit excluded.
 */
class testProgram {
private:
    Menu menu;
public:
    void setAccountNr();
    void enQueue();
    void deQueue();
    void isEmpty() const;
    void isFull() const;
    void nrElements() const;
    void capacity();
    testProgram();
    void run();
};
#endif