//
// Created by Marcus Roos on 2020-10-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_MAINPROGRAM_H
#define DT060G_MAINPROGRAM_H

#include <list>
#include <iostream>
#include <limits>
#include "ListManipulator.hpp"

/*Two help functions, startFunc is there to ask which type the user want to use.
 * Print menu is there to print the actual menu options. */
void startFunc();
void printMenu();

/*The mainmenu function, this will initialize the constructor for the
 * listManipulator and enter a switch which will run until the user decide
 * they want to exit out of the program. This function will handle all
 * the function calls done to the listManipulator.*/
template<typename T>
void mainMenu(std::list<T> myList){
    ListManipulator<T> listManipulator(&myList);
    int tmpInt=0;
    T tmp;
    T min, max;
    bool loop=true;
    while (loop) {
        printMenu();
        std::cin >> tmpInt;
        while (tmpInt < 1 || tmpInt > 13 || std::cin.fail()) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> tmpInt;
        }
        switch (tmpInt) {
            case 1: {
                listManipulator.fillList();
                break;
            }
            case 2: {
                listManipulator.sumList();
                break;
            }
            case 3: {
                listManipulator.listAverage();
                break;
            }
            case 4: {
                listManipulator.findFirst1500_1900(tmp);
                break;
            }
            case 5: {
                listManipulator.DivideByTwo();
                break;
            }
            case 6: {
                listManipulator.swapPlaces();
                break;
            }
            case 7: {
                listManipulator.findMinMax(min, max);
                break;
            }
            case 8: {
                listManipulator.sortList();
                break;
            }
            case 9: {
                listManipulator.clearList();
                break;
            }
            case 10: {
                listManipulator.saveToFile();
                break;
            }
            case 11: {
                listManipulator.readFromFile();
                break;
            }
            case 12: {
                listManipulator.getList();
                break;
            }
            case 13: {
                loop = false;
                break;
            }
        }
    }
}



#endif //DT060G_MAINPROGRAM_H
