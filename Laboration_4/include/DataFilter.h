//
// Created by  on 2020-10-10.
//
// StudentID:
//

#ifndef DT060G_DATAFILTER_H
#define DT060G_DATAFILTER_H

template<typename T>
class DataFilter {
public:
    DataFilter(DataFileReader<T> *aReader, T aMin, T aMax);
    /* pre: aReader points to an instance of DataFileReader<T> for which openFiles() has been succesfully called. */
    bool getNextValue(T &aValue); /* pre: an earlier call to getNextValue() has not returned false. post: true is returned if aValue holds a value read from aReader. If a value could not be read, false is returned. If a value is read but is not within the interval specified by aMin and aMax parameters to the constructor, a range_error exception is thrown. */
private:
    //... necessary members
};

#endif //DT060G_DATAFILTER_H
