#include "DataFilter.h"
#include "DataFileReader.h"
#include <string>
//#include "memstat.hpp"

int main() {
    // Declares and initialize a double to be used with the dataFilter class
    double dummy=0;
    // Declare and initialize two strings with the names of the two files
    // we'll be using
    std::string datafilename = "Values.dat";
    std::string errorfilename = "ReadErrors.dat";
    //Calls the constructor in DataFileReader, using aforementioned strings
    DataFileReader<double> dataFileReader(datafilename, errorfilename);
    /*Calls openFiles function in dataFileReader object, this will determine
     * if two files named "Values.dat" and "ReadErrors.dat" actually exist. */
    dataFileReader.openFiles();
    /*Creates an instance of DataFilter by calling its constructor, uses
     * a pointer to the dataFileReader object as well as minimum and maximum
     * values of type double to construct*/
    DataFilter<double> dataFilter(&dataFileReader, 0.0, 10.0);
    //Calls getNextValue in the dataFilter object, using a double as parameter
    dataFilter.getNextValue(dummy);

    return 0;
}
