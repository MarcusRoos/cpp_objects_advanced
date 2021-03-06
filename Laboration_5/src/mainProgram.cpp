//
// Created by Marcus Roos on 2020-10-14.
// Mittuniversitet
// StudentID: Maro1904
//
#include "mainProgram.h"

/*Implementation for the startFunc, basically a switch which allows
 * the user to choose if they want to use double or int with the list.*/
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

/*Prints the main menus options when called, does nothing else.*/
void printMenu(){
    std::cout << "1. Fill list with random numbers" << std::endl;
    std::cout << "2. Summerizes the values in the list" << std::endl;
    std::cout << "3. Average of numbers" << std::endl;
    std::cout << "4. Find first number between 1500 and 1900" << std::endl;
    std::cout << "5. Divide by two" << std::endl;
    std::cout << "6. Swap places" << std::endl;
    std::cout << "7. Find largest and smallest number" << std::endl;
    std::cout << "8. Sort" << std::endl;
    std::cout << "9. Clear list" << std::endl;
    std::cout << "10. Write to file" << std::endl;
    std::cout << "11. Read from file" << std::endl;
    std::cout << "12. Print numbers" << std::endl;
    std::cout << "13. Exit" << std::endl;
}