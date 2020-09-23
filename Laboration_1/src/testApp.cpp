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
    std::cout << "Enter size of queue, between 1-100000: " << std::endl;
    Type choice=0;
    std::cin >> choice;
    while (std::cin.fail() || choice <1 || choice >100000){
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    std::unique_ptr<QueueQ> my_ptr(new QueueQ(choice));
    testQueue = std::move(my_ptr);
    menu.setenableMenu();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

/**
The enqueue function, this function once called will first of all determine if
 there's a spot in the queue, if there isn't any available spot in the queue it
 will inform the user and exit the function. If there is however a spot in the
 queue, the user will be asked to enter a number once again between 1 and 100000
 to add to the queue. If the input matches the criteria this number will be
 added as an element in the queue by calling the enqueue function in the
 QueueQ class.
*/
void testApp::enQueue() {
    if (testQueue->length() < testQueue->capacity()){
        Type eleQueue=0;
        std::cout << "Enter element to be queued, "
                     "integer between 1 and 100000" << std::endl;
        std::cin >> eleQueue;
        while (std::cin.fail() || eleQueue <1 || eleQueue >100000){
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> eleQueue;
        }
        testQueue->enqueue(eleQueue);
    }
    else{
        std::cout << "Queue is full! " << std::endl;
    }
}

/**
The dequeue function, it will first of all check whether the queue is
 empty or not, if the function is empty it will inform the user and exit.
 If there is however an element in the queue this element will be removed, and
 a reference will tell the user which element got removed.
*/
void testApp::deQueue() {
    Type reference=0;
    if (testQueue->empty()){
        std::cout << "Queue is empty, did not remove any entries! " << std::endl;
    }
    else {
        testQueue->dequeue(reference);
        std::cout << "Deleting element: " << reference << std::endl;
    }
}

/**
The is empty function, the empty function will check if the queue is
 empty or not, it will point towards a function in the QueueQ class to determine
 this. If the queue is empty the user will be informed, if its not, the user
 will be informed of that as well.
*/
void testApp::isEmpty() const {
    if (testQueue->empty()){
        std::cout << "Queue is empty. " << std::endl;
    }
    else{
        std::cout << "Queue isn't empty. " << std::endl;
    }
}

/**
The is full function, the full function will check if the queue is
 full or not, it will point towards a function in the QueueQ class to determine
 this. If the queue is full the user will be informed, if its not, the user
 will be informed of that as well.
*/
void testApp::isFull() const {
    if (!testQueue->full()){
        std::cout << "Queue isn't full. " << std::endl;
    }
    else{
        std::cout << "Queue is full. " << std::endl;
    }
}

/**
The is the nr of elements function, this function will check the amount of
 elements found within the queue,
 it will point towards a function in the QueueQ class to determine
 this. The number of elements will be printed out on the screen by calling
 a function in the QueueQ class.
*/
void testApp::nrElements() const {
    std::cout << "Number of elements in queue:  " << testQueue->length() << std::endl;
}

/**
The maximum capacity function, this function will ask the QueueQ function
 what the maximum capacity of the queue is, and use this as a pointer to
 tell the user how many elements the queue can fit at max capacity.
*/
void testApp::capacity(){
    std::cout << "Maximum capacity " << std::endl;
    std::cout << "MAX: " << testQueue->capacity() << std::endl;
}

/**
Extra menu to make sure a queue has been created, instead of simply shutting
 off the other options this works as an extra safety measurement.
 If a queue is created the other menu options will be visible and free to
 choose from.
*/
void testApp::runSubMenu() {
        std::cout << "1. Create Queue" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 1 || choice > 2) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
                createQueue();
                run();
                break;
            case 2:
            default:
                break;
        }
}