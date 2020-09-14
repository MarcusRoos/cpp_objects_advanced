//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_MAINMENU_H
#define DT060G_MAINMENU_H
#include "Menu.h"
#include "QueueQ.h"
#include "Management.h"
#include <fstream>
#include <vector>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
class MainMenu {
private:
    Menu menu;
    std::unique_ptr<QueueQ>testQueue;
    void createQueue();
    void enQueue();
    void deQueue();
    void isEmpty() const;
    void isFull() const;
    void nrElements() const;
    void capacity();
public:
    MainMenu();
    void run();
};
#endif