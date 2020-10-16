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
#include <functional>
#include <iterator>
#include <ctime>
#include <typeinfo>
#include <cstring>

template<typename T>
class ListManipulator{
private:
    std::list<T> *theList;
public:
    ListManipulator(std::list<T> *aList);
    ~ListManipulator(){};
    void fillList();
    void sumList() const;
    void listAverage() const;
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
void ListManipulator<T>::sumList() const {
   std::cout << "Summary: " <<std::accumulate(theList->begin(), theList->end(),
           0.0) << std::endl;
}

template<typename T>
void ListManipulator<T>::listAverage() const {
    T avg=0;
    avg = std::accumulate(theList->begin(), theList->end(), 0.0);
    avg = avg/20;
    std::cout << "Average: " << avg << std::endl;
}

template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &num) const {
    /*I wasn't entirely sure if we were meant to find the first number
 * between 1500-1900 as in the lowest number in this interval, or simply
 * the first one in an unsorted list (i.e. 1678 at #1 in the list but
 * 1675 at #3 would return 1678 as its the first value "found".
 * If that was the plan, simply remove everything the comments below, and add
     * comments to the active code.*/
/**         //  Inactive code
    auto it = find_if(theList->begin(), theList->end(), [](T a) {
        return a >= 1500 && a <=1900;
    });
    if (it != theList->end()){
        num = *it;
        std::cout <<"Smallest value between 1500 and 1900 = " <<num << std::endl;
        return true;
    }
    else
        return false;
    **/

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
        std::cout <<"Smallest value between 1500 and 1900 = " <<num << std::endl;
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
    std::cout <<"Min: " <<min << std::endl;
    std::cout <<"Max: " <<max << std::endl;
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
    fs.close();
    std::cout << "Saved." << std::endl;
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
    if(!inFile.is_open()){
        std::cout << "Could not locate any file of loaded type."
                     " \nPlease create a list first with "
                     "your currently loaded type, then proceed"
                     " to save it." << std::endl;
    }
    else {
        std::istream_iterator<T> tmpIt;
        std::istream_iterator<T> in(inFile);
        std::copy(in, tmpIt, std::back_inserter(*theList));
    }

}

#endif //DT060G_LISTMANIPULATOR_HPP