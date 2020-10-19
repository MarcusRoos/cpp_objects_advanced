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
                getType();
                break;
            case 2:
                getID();
                break;
            case 3:
                getSeats();
                break;
            case 4:
                getInternet();
                break;
            case 5:
                std::cout << "Boop 5" << std::endl;
                break;
            case 6:
                assembleTrain();
                break;
            case 7:
                trainTest();
                break;
            case 8:
                again = false;
                break;
        }
    }while(again);
}

SimulationProgram::SimulationProgram() {
    menu.setTitle("**** Class test menu ****");
    menu.addItem("Get type", true);
    menu.addItem("Get ID", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("Construct test train", true);
    menu.addItem("Exit", true);
}

void SimulationProgram::runSubMenu() {
    std::cout << "===== Start Menu =====" << std::endl;
    std::cout << "1. Change start time [00:00]" << std::endl;
    std::cout << "2. Change end time [23:59]" << std::endl;
    std::cout << "3. Start simulation" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter choice" << std::endl;
    int choice = 0;
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > 3) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    if (choice == 0){
        choice = 4;
    }
    switch (choice) {
        case 1:
            run();
            break;
        case 2:
            run();
            break;
        case 3:
            run();
            break;
        case 4:
        default:
            break;
    }
}

void SimulationProgram::getType() {
    std::cout << "Test Type " << std::endl;
}

void SimulationProgram::getID() {
    std::cout << "Test ID " << std::endl;

}
void SimulationProgram::getSeats() {
    std::cout << "Test Seats " << std::endl;

}
void SimulationProgram::getInternet() {
    std::cout << "Test Internet " << std::endl;

}

void SimulationProgram::trainTest() {
    testStation.testStat();
}

void SimulationProgram::assembleTrain() {
    std::cout << "Assembling train" << std::endl;

}

void SimulationProgram::loadFiles() {

}
