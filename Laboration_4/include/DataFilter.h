//
// Created by  on 2020-10-10.
//
// StudentID:
//

#ifndef DT060G_DATAFILTER_H
#define DT060G_DATAFILTER_H

#include "DataFileReader.h"

template<typename T>
class DataFilter {
public:
    DataFilter(DataFileReader<T> *aReader, T aMin, T aMax);
    bool getNextValue(T &aValue);
private:
    DataFileReader<T> *reader;
    T minRange;
    T manRange;
};

#endif //DT060G_DATAFILTER_H
