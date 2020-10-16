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
#include <typeinfo>
#include <string>
#include <cstring>

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
    return std::accumulate(theList->begin(), theList->end(), T(0)/theList->size());
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
        std::cout <<"Smallest value between 1500 and 190 = " <<num << std::endl;
        return true;
    }
    else
    return false;
}

template<typename T>
void ListManipulator<T>::DivideByTwo() {
    std::transform(theList->begin(), theList->end(), theList->begin(),
            std::bind(std::divides<T>(),std::placeholders::_1, 2));
}

template<typename T>
void ListManipulator<T>::swapPlaces() {
    std::_List_iterator<T> fIt=theList->begin(), bIt=theList->end();
    bIt--;
    for (size_t i=0; i<theList->size()/2; i++) {
        std::iter_swap(fIt, bIt);
        fIt++;
        bIt--;
    }
}

template<typename T>
void ListManipulator<T>::findMinMax(T &min, T &max) const {
    std::list<T> tmpList;
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++) {
        tmpList.push_back(*it);
    }
    tmpList.sort();
    min = *std::min_element(theList->begin(), theList->end());
    max = *std::max_element(theList->begin(), theList->end());
}

template<typename T>
void ListManipulator<T>::sortList() {
    theList->sort();
    std::cout << "List sorted." << std::endl;
}

template<typename T>
void ListManipulator<T>::clearList() {
    theList->clear();
    std::cout << "List cleared." << std::endl;
}

template<typename T>
void ListManipulator<T>::getList() const {
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++)
        std::cout << (*it) << std::endl;
}

template<typename T>
void ListManipulator<T>::saveToFile() const {
    std::ofstream fs;
    const std::type_info& ti1 = typeid(T);
    if (strncmp (ti1.name(),"i", 1) == 0){
        fs.open("list_integer.dat");
    }
    if (strncmp (ti1.name(),"d", 1) == 0){
        fs.open("list_double.dat");
    }
    std::copy(theList->begin(), theList->end(), std::ostream_iterator<T>(fs, "\n"));
    fs << "\n";
    std::cout << "Save to file" << std::endl;
}

template<typename T>
void ListManipulator<T>::readFromFile() {
    std::ifstream inFile;
    const std::type_info& ti1 = typeid(T);
    if (strncmp (ti1.name(),"i", 1) == 0){
        inFile.open("list_integer.dat");
    }
    if (strncmp (ti1.name(),"d", 1) == 0){
        inFile.open("list_double.dat");
    }
    std::istream_iterator<T> eos;
    std::istream_iterator<T> iit(inFile);
    std::copy(iit, eos, std::back_inserter(*theList));

    std::cout << "Read from file" << std::endl;
}


#endif //DT060G_LISTMANIPULATOR_HPP
