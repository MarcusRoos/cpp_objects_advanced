//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testProgram.h"

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/
void testProgram::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                setAccountNr();
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
The testApp constructor, adds menu items to determine which items are enabled
 as well as disabled by default.
*/
testProgram::testProgram() {
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


void testProgram::enQueue() {

}

void testProgram::deQueue() {

}


void testProgram::isEmpty() const {

}

void testProgram::isFull() const {

}

void testProgram::nrElements() const {

}

void testProgram::capacity(){

}

void testProgram::setAccountNr() {

}
