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
    std::ofstream rangeError("ReadErrors.dat");
    bool notEndOfFile;
    double value=0;
    notEndOfFile = reader->readNextValue(aValue);
    while (notEndOfFile){
        try{
            notEndOfFile = reader->readNextValue(aValue);
            value = aValue;
            if (notEndOfFile){
                if (value < minRange || value > maxRange) {
                    throw std::range_error("Some error in the range!");
                }
                sum += value;
                amount++;
                average = sum/amount;
            }
        }
            catch (std::range_error & e)
            {
                outside++;
                std::cout << "outside" << outside << std::endl;
                rangeError << e.what() << std::endl;
            }

    }
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Outside: " << outside << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Avg: " << average << std::endl;
    rangeError.close();
    return false;
}

#endif //DT060G_DATAFILTER_H
