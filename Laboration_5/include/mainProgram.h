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

void startFunc();
void printMenu();

template<typename T>
void mainMenu(std::list<T> myList){
    ListManipulator<T> listManipulator(&myList);
    int tmpInt=0;
    T sum;
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
