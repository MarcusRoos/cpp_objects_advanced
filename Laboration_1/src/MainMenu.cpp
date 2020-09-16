//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "MainMenu.h"
#include <iostream>
#include <iomanip>

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/
void MainMenu::run() {
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

void MainMenu::createQueue() {
    Type B = 0;
    std::cout << "Enter size of queue: " << std::endl;
    std::cin >> B;
    std::unique_ptr<QueueQ> my_ptr(new QueueQ(B));
    testQueue = std::move(my_ptr);
    menu.setenableMenu();
}


MainMenu::MainMenu() {
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

void MainMenu::enQueue() {
    if (testQueue->length() < testQueue->capacity()){
        std::cout << "Enter size of the integer to add to queue:  " << std::endl;
        Type input=0;
        std::cin >> input;
        testQueue->enqueue(input);
    }
    else{
        std::cout << "Queue is full! " << std::endl;
    }
}

void MainMenu::deQueue() {
    if (testQueue->empty()){
        std::cout << "Queue is empty, did not remove any entries! " << std::endl;
    }
    else {
        Type reference;
        testQueue->dequeue(reference);
        std::cout << "reference: " << reference << std::endl;
    }
}

void MainMenu::isEmpty() const {
    if (testQueue->empty()){
        std::cout << "Queue is empty. " << std::endl;
    }
    else{
        std::cout << "Queue isn't empty. " << std::endl;
    }
}

void MainMenu::isFull() const {
    if (!testQueue->full()){
        std::cout << "Queue isn't full. " << std::endl;
    }
    else{
        std::cout << "Queue is full. " << std::endl;
    }
}

void MainMenu::nrElements() const {
    std::cout << "Number of elements in queue:  " << testQueue->length() << std::endl;
}

void MainMenu::capacity(){
    std::cout << "Maximum capacity " << std::endl;
    std::cout << "MAX: " << testQueue->capacity() << std::endl;
}
