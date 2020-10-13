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

//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class DataFilter

Handles the customers within the bank, will use another class "Account"
 where it will store the information regarding the actual account, while
 this customer class will instead handle the information regarding
 the customer and not the actual accounts. This is a silent class.
 */

template<typename T>
class DataFilter {
public:
    DataFilter(DataFileReader<T> *aReader, T aMin, T aMax) :
            reader(aReader), minRange(aMin), maxRange(aMax) {}
    bool getNextValue(T &aValue);
private:
    // Private member of type DataFileReader pointing to reader
    DataFileReader<T> *reader;
    // Declare min and maxrange values as type T (double in this case)
    T minRange;
    T maxRange;
    // Declare doubles (could also be declared as T here) to store data
    double sum=0, amount=0, average=0;
   // Declares an int to keep track of how many times a value is outside min/max
    int outside=0;
};

/**
The getNextValue, this function will declare and initialize an output stream
 to a file called "RangeErrors.dat" where any values will be outside the max
 and min range will be written to. The function will be called once, open
 this output stream and declare a string variable, it will then enter a
 while loop. This while loop will run until the function call will return
 false, the function call is the aforementioned pointer calling the
 readNextValue function from DataFileReader class, a reference to the value
 processed within this function will be held by &aValue, which is also sent as
 a parameter to the readNextValue function. If the reference value is
 outside the min and max range the function will throw a range error
 which will in turn write the reference value to a file called
 "RangeErrors.dat". If the value held by aValue isn't outside the min/max range
 the sum will be increased by that of the value and amount increased by 1.
 At the end of the function the file named "ReadErrors.dat" defined by
 DataFileReader class will be opened once more, the amount of newlines will be
 counted and stored in a separate variable, once done the file instream to the
 file will be closed, 1 will be removed from the counter as new lines in a
 file always count one more than the actual lines due to reading a new line
 at the end of file. The amount of numerical values read will be deducted by
 this counter as to remove non numerical values, the average will be
 calculated the all data finally printed on the screen for the user to see.
 */
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
