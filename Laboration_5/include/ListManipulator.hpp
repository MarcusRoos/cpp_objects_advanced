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
    void getList() const;
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
    theList->resize(20);
    static std::default_random_engine rng(unsigned(time(0)));
    std::uniform_real_distribution<double> distribution(1000, 2000);
    std::generate(theList->begin(), theList->end(), [&]{
        T number = distribution(rng);
        return number;
    });
}

template<typename T>
T ListManipulator<T>::sumList() const {
    T sum = std::accumulate(theList->begin(), theList->end(), 0.0);
    return sum;
}

template<typename T>
T ListManipulator<T>::listAverage() const {
    T avg = std::accumulate(theList->begin(), theList->end(), 0.0);
    int amount = theList->size();
    avg /= amount;
    return avg;
}

template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &num) const {
    std::list<T> tmpList;
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++) {
        tmpList.push_back(*it);
    }
    tmpList.sort();
    auto it = find_if(tmpList.begin(), tmpList.end(), [](T a) {
        return a >= 1500 && a <=1900;
    });
    if (it != tmpList.end()){
        num = *it;
        std::cout <<"NUM: " <<num << std::endl;
        return true;
    }
    else
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
void ListManipulator<T>::getList() const {
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++)
        std::cout << (*it) << std::endl;
}

template<typename T>
void ListManipulator<T>::saveToFile() const {

}

template<typename T>
void ListManipulator<T>::readFromFile() {
}


#endif //DT060G_LISTMANIPULATOR_HPP
