//
// Created by  on 2020-10-10.
//
// StudentID:
//

#ifndef DT060G_DATAFILTER_H
#define DT060G_DATAFILTER_H

#include <iostream>
#include "DataFileReader.h"
#include <stdexcept>

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
    double sum=0, amount=0, average=0;
    int outside=0;
};

template<typename T>
bool DataFilter<T>::getNextValue(T &aValue) {
    std::string errorstring="Value outside interval: ";
    std::ofstream rangeError("RangeErrors.dat");
    bool notEndOfFile = true;
    while (notEndOfFile){
        try{
            notEndOfFile = reader->readNextValue(aValue);
            if (notEndOfFile){
                if (aValue < minRange || aValue > maxRange) {
                    throw std::range_error(errorstring);
                }
                else
                sum += aValue;
                amount++;
            }
        }
            catch (std::range_error & e)
            {
                rangeError << e.what() << aValue << std::endl;
                outside++;
            }

    }
    rangeError.close();

    std::string s;
    int totalLines=0;
    std::ifstream deleteLines;
    deleteLines.open("readErrors.dat");
    while(!deleteLines.eof()) {
        getline(deleteLines, s);
        totalLines ++;
    }
    totalLines-=1;

    deleteLines.close();

    amount -= totalLines;
    average = sum/amount;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Outside: " << outside << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Avg: " << average << std::endl;
    return false;
}

#endif //DT060G_DATAFILTER_H
