//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "SimulationProgram.h"
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
void SimulationProgram::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                std::cout << "Boop 1" << std::endl;
                testPtr();
                break;
            case 2:
                std::cout << "Boop 2" << std::endl;
                break;
            case 3:
                std::cout << "Boop 3" << std::endl;
                break;
            case 4:
                std::cout << "Boop 4" << std::endl;
                break;
            case 5:
                std::cout << "Boop 5" << std::endl;
                break;
            case 6:
                std::cout << "Boop 6" << std::endl;
                break;
            case 7:
                std::cout << "Boop 7" << std::endl;
                break;
            case 8:
                again = false;
                break;
        }
    }while(again);
}

SimulationProgram::SimulationProgram() {
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

void SimulationProgram::runSubMenu() {
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
            run();
            break;
        case 2:
        default:
            break;
    }
}

void SimulationProgram::testPtr() {
    std::cout << "Test PTR " << std::endl;
    testVehicle.push_back(std::unique_ptr<OpenFreight>(
                new OpenFreight()));
    std::cout << "ID:" << testVehicle[0]->getId() << std::endl;
    std::cout << "Type:" << testVehicle[0]->getType() << std::endl;
}
