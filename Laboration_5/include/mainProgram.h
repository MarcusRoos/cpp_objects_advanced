//
// Created by Marcus Roos on 2020-10-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_MAINPROGRAM_H
#define DT060G_MAINPROGRAM_H

#include <list>
#include <iostream>

void startFunc();
void mainMenu();
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
T myInit(std::list<T> &myList){
    std::cout << "Hej" << std::endl;
}

#endif //DT060G_MAINPROGRAM_H
