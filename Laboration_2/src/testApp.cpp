//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testApp.h"
#include <iostream>
#include <iomanip>
#include <limits>

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/
void testApp::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                createQueue();
                break;
            case 2:
                enQueue();
                break;
            case 3:
                deQueue();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            case 6:
                nrElements();
                break;
            case 7:
                capacity();
                break;
            case 8:
                again = false;
                break;
        }
    }while(again);
}

/**
The create queue function, this function will start by asking the user for
 an input, this input will be sent to another function in the QueueQ
 class, where an array in an unique ptr will be created. This array queue
 will be moved to another unique ptr within the testapp class. The size of
 the queue is hardcoded to be set between 1 and 100000, only numbers are
 acceptable and within the chosen interval. If a queue already exists the
 previous one will be written over.
*/
void testApp::createQueue() {

}

/**
The testApp constructor, adds menu items to determine which items are enabled
 as well as disabled by default.
*/
testApp::testApp() {
    menu.setTitle("**** Array pointer queue ****");
    menu.addItem("Create queue", true);
    menu.addItem("Add element to queue", false);
    menu.addItem("Delete element from queue", false);
    menu.addItem("Check Empty", false);
    menu.addItem("Check Full", false);
    menu.addItem("Check number of elements", false);
    menu.addItem("Check maximum capacity", false);
    menu.addItem("Exit", true);
}


void testApp::enQueue() {

}

void testApp::deQueue() {

}


void testApp::isEmpty() const {

}

void testApp::isFull() const {

}

void testApp::nrElements() const {

}

void testApp::capacity(){

}