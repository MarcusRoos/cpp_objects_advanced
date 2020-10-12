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
    double sum, amount, average;
    int outside;
};

template<typename T>
bool DataFilter<T>::getNextValue(T &aValue) {
    std::ofstream rangeError("ReadErrors.dat");
    bool notEndOfFile;
    double value=0;
    notEndOfFile = reader->readNextValue(aValue);
    while (notEndOfFile){
        try{
            notEndOfFile = reader->readNextValue(aValue);
            value = aValue;
            if (notEndOfFile){
                sum += value;
                amount++;
                average = sum/amount;
                std::cout << "aValue: " << aValue << std::endl;
            }
        }
        catch (std::range_error &e){
            outside++;
            std::cout << "outside" << outside << std::endl;
            rangeError << e.what() << std::endl;
        }
    }
    return false;
}

#endif //DT060G_DATAFILTER_H
