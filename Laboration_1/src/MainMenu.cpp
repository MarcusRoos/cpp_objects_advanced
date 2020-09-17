//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "MainMenu.h"
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

void MainMenu::deQueue() {
    Type reference=0;
    if (testQueue->empty()){
        std::cout << "Queue is empty, did not remove any entries! " << std::endl;
    }
    else {
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
