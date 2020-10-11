//
// Created by on 2020-10-10.
//
// StudentID:
//

#include "DataFilter.h"
#include <memory>

template<typename T>
DataFilter<T>::DataFilter(DataFileReader <T> *aReader, T aMin, T aMax) {

}

template<typename T>
bool DataFilter<T>::getNextValue(T &aValue) {
    return false;
}
