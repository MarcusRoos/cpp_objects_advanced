//
// Created by Marcus Roos on 2020-10-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_LISTMANIPULATOR_HPP
#define DT060G_LISTMANIPULATOR_HPP
#include <list>
#include <random>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

template<typename T>
class ListManipulator{
private:
    std::list<T> *theList;
public:
    ListManipulator(std::list<T> *aList);
    ~ListManipulator(){};
    void fillList();
    T sumList() const;
    T listAverage() const;
    bool findFirst1500_1900(T &num) const;
    void DivideByTwo();
    void swapPlaces();
    void findMinMax(T &min, T &max) const;
    void sortList();
    void clearList();
    std::list<T> getList() const;
    void saveToFile() const;
    void readFromFile();
};

template<typename T>
ListManipulator<T>::ListManipulator(std::list<T> *aList) {
    theList = aList;
}

template<typename T>
void ListManipulator<T>::fillList() {
    theList->clear();
    static std::default_random_engine generator(unsigned(time(0)));
    std::uniform_real_distribution<double> distribution(1000, 2000);
    for (int i=0; i<20; i++){
        double number = distribution(generator);
        theList->push_back(number);
    }
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++)
        std::cout << (*it) << std::endl;
}

template<typename T>
T ListManipulator<T>::sumList() const {
    T sum = std::accumulate(theList->begin(), theList->end(), 0.0);
    return sum;
}

template<typename T>
T ListManipulator<T>::listAverage() const {
    return nullptr;
}

template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &num) const {
    return false;
}

template<typename T>
void ListManipulator<T>::DivideByTwo() {

}

template<typename T>
void ListManipulator<T>::swapPlaces() {

}

template<typename T>
void ListManipulator<T>::findMinMax(T &min, T &max) const {

}

template<typename T>
void ListManipulator<T>::sortList() {

}

template<typename T>
void ListManipulator<T>::clearList() {
    theList->clear();
}

template<typename T>
std::list<T> ListManipulator<T>::getList() const {
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++)
        std::cout << (*it) << std::endl;
    return theList;
}

template<typename T>
void ListManipulator<T>::saveToFile() const {

}

template<typename T>
void ListManipulator<T>::readFromFile() {
    auto start = theList->begin(), stop = theList->end();
        for (auto it = start; it != stop; it++)
            std::cout << (*it) << std::endl;
}

#endif //DT060G_LISTMANIPULATOR_HPP
