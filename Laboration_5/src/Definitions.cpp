#include "Prototypes.h"
#include <iostream>
#include <limits>

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
            int initInt = 0;
            std::cout << "Integer." << std::endl;
            break;
        }
        case 2: {
            double initDouble=0;
            std::cout << "Double." << std::endl;
            break;
        }
    }
}
