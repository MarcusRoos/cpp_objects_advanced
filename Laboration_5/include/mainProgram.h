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
void fillList();
void listAvarage();
void findFirst1500_1900();
void divideByTwo();
void findMinMax();
void sortList();
void clearList();
void printList();
void saveToFile();
void readFromFile();

template<typename T>
void mainMenu(std::list<T> myList){
    ListManipulator<T> listManipulator(&myList);
    int tmpInt=0;
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
                fillList();
                listManipulator.fillList();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                break;
            }
            case 10: {
                break;
            }
            case 11: {
                listManipulator.readFromFile();
                break;
            }
            case 12: {
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
