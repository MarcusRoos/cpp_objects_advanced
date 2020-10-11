//
// Created by  on 2020-10-10.
//
// StudentID:
//

#ifndef DT060G_DATAFILTER_H
#define DT060G_DATAFILTER_H

#include <iostream>
#include "DataFileReader.h"

template<typename T>
class DataFilter {
public:
    DataFilter(DataFileReader<T> *aReader, T aMin, T aMax) :
            reader(aReader), minRange(aMin), maxRange(aMax) {}
    bool getNextValue(T &aValue);
private:
    DataFileReader<T> *reader;
    T minRange;
    T maxRange;
};

template<typename T>
bool DataFilter<T>::getNextValue(T &aValue) {
    double test;
    while (reader->readNextValue(test)) {
    }
    return false;
}

#endif //DT060G_DATAFILTER_H
