//
// Created by Marcus Roos on 2020-10-14.
// Mittuniversitet
// StudentID: Maro1904
//
#include "mainProgram.h"

void startFunc() {
    std::cout << "Int or Double?" << std::endl;
    std::cout << "1. Int" << std::endl;
    std::cout << "2. Double" << std::endl;
    int tmpInt=0;
    std::cin >> tmpInt;
    while (tmpInt < 1 || tmpInt > 2 || std::cin.fail()) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpInt;
    }
    switch (tmpInt){
        case 1: {
            std::list<int>intList;
            std::cout << "Integer." << std::endl;
            mainMenu(intList);
            break;
        }
        case 2: {
            std::list<double>dblList;
            std::cout << "Double." << std::endl;
            mainMenu(dblList);
            break;
        }
    }
}