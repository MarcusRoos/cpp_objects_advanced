//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TESTAPP_H
#define DT060G_TESTAPP_H
#include "Menu.h"
#include "QueueQ.h"
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
class testApp {
private:
    Menu menu;
    std::unique_ptr<QueueQ>testQueue; // Creates a unique pointer
public:
    /**
* Create a queue of unique pointer
*
* @param None.
* @return None.
*/
    void createQueue();
    /**
* Adds an item to the queue
*
* @param None.
* @return None.
*/
    void enQueue();
    /**
* Removes an item from the queue
*
* @param None.
* @return None.
*/
    void deQueue();
    /**
* Checks whether the queue is empty or not
*
* @param None.
* @return None.
*/
    void isEmpty() const;
    /**
* Checks whether the queue is full or not
*
* @param None.
* @return None.
*/
    void isFull() const;
    /**
* Check the current amount of elements in the queue
*
* @param None.
* @return None.
*/
    void nrElements() const;
    /**
* Checks the maximum capacity of the queue
*
* @param None.
* @return None.
*/
    void capacity();
public:
    /**
* testApp, sets menuitems to display the menu
*
* @param None.
* @return None.
*/
    testApp();
    /**
* run function, starts up the whole program
*
* @param None.
* @return None.
*/
    void run();
};
#endif