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

void startFunc();
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
void mainMenu(std::list<T> &myList){
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
    int tmpInt=0;
    bool loop=true;
    while (loop) {
        std::cin >> tmpInt;
        while (tmpInt < 1 || tmpInt > 13 || std::cin.fail()) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> tmpInt;
        }
        switch (tmpInt) {
            case 1: {
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
