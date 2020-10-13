//
// Created by  on 2020-10-10.
//
// StudentID:
//

#ifndef DT060G_DATAFILEREADER_H
#define DT060G_DATAFILEREADER_H
#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>

//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class DataFileReader

This class handles the opening and verification of files, as well as all the
 reading from files. The intent of the class is to verify that the relevant
 files actually do exist and can be found, as well as read the next item in
 a text file, separated by new line. This class is a template meaning the type
 of the class will be dependant on usage, in this case a double will be used.
 */

template<typename T>
class DataFileReader {
public:
    DataFileReader(std::string aDataFileName, std::string aErrorFileName); /* pre: A file named aDataFile contains values to read. */
    ~DataFileReader(); /* post: Files are closed */
    void openFiles(); /* post: An input stream from the file named aDataFile and an output stream to the file named aErrorFile are opened. If either of these operations fails a runtime_error exception is thrown. */
    bool readNextValue(T &aValue); /* pre: openFiles has been successfully called. post: If a value has been successfully read, aValue holds that value and true is returned. Else, the read operation encountered an end-of-file and false is returned. */
private:
    //Two strings to store the name of the read and error files
    std::string dataFile;
    std::string errorFile;
    //Declaring an in and out stream for the data respective errorfiles.
    std::ifstream data;
    std::ofstream readError;
};

/**
The constructor, requires two string parameters upon initialization, the
 parameters will be stored in the aforementioned string variables
 marked as private class members. Those values will dictate the name of the
 file to read values from, and the file where unaccepted characters will
 be written to.
 */
template<typename T>
DataFileReader<T>::DataFileReader(std::string aDataFileName,
                                  std::string aErrorFileName) {
    dataFile = aDataFileName;
    errorFile = aErrorFileName;
}

/**
The openFiles function will try to open the in and outstreams
 declared as private members with the file names passed down into the
 constructor when the class was initialized. If either file cannot be
 opened a runtime error will be thrown and the program will exit with an
 error code.
 */
template<typename T>
void DataFileReader<T>::openFiles() {
    readError.open(errorFile);
    if (!readError.is_open())
        throw std::runtime_error("could not open errorfile");
    data.open(dataFile);
    if (!data.is_open())
        throw std::runtime_error("could not open datafile");
}

/**
The readNextValue function will start off by creating an exception mask which
 will be used to filter out values that cannot be converted to the objects
 type, in this case a double. This mask will then be applied to the instream, a
 value from the file will be read in and stored in aValue, if this
 happens the input was successfully converted to a double and true is returned,
 if it cannot be converted the function will instead catch the bad value.
 If it reached the end of file false will be returned, else it will assume
 the value couldn't be converted to a double and write the bad value to the
 error file.
 */
template<typename T>
bool DataFileReader<T>::readNextValue(T &aValue) {
    using namespace std;
    std::ios_base::iostate mask = ios::eofbit | ios::failbit | ios::badbit;
    data.exceptions(mask);
    try{
        data >> aValue;
        data.get();
        return true;
    }
    catch (ios_base::failure &eo){
        ios_base::iostate flags = data.rdstate();
        if (flags & ios::eofbit){
            data.clear();
            return false;
        }
        else{
            std::string error;
            data.clear();
            getline(data,error);
            readError << error << std::endl;
        }
    }
    return true;
}

/**
Default destructor for the class
 */
template<typename T>
DataFileReader<T>::~DataFileReader() {

}
#endif //DT060G_DATAFILEREADER_H
