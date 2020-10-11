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
#include <iostream>
#include <fstream>

template<typename T>
class DataFileReader {
public:
    DataFileReader(std::string aDataFileName, std::string aErrorFileName); /* pre: A file named aDataFile contains values to read. */
    ~DataFileReader(); /* post: Files are closed */
    void openFiles(); /* post: An input stream from the file named aDataFile and an output stream to the file named aErrorFile are opened. If either of these operations fails a runtime_error exception is thrown. */
    bool readNextValue(T &aValue); /* pre: openFiles has been successfully called. post: If a value has been successfully read, aValue holds that value and true is returned. Else, the read operation encountered an end-of-file and false is returned. */
private:
    std::string dataFile;
    std::string errorFile;
};

template<typename T>
DataFileReader<T>::DataFileReader(std::string aDataFileName,
                                  std::string aErrorFileName) {
    dataFile = aDataFileName;
    errorFile = aErrorFileName;
}

template<typename T>
void DataFileReader<T>::openFiles() {
    std::ifstream error(errorFile);
    error.open(errorFile);
    if (!error.is_open())
        throw std::runtime_error("could not open errorfile");
    std::ifstream data(dataFile);
    data.open(errorFile);
    if (!data.is_open())
        throw std::runtime_error("could not open datafile");

}

template<typename T>
bool DataFileReader<T>::readNextValue(T &aValue) {
    std::cout << "TestRead" << std::endl;
    /*
    ios_base::iostate mask = ios::eofbit | ios::failbit | ios::badbit;
    dataFile.exceptions(mask);
    try{
        dataFile >> aValue;
        return true;
    }
    catch (ios_base::failure &eo){
        ios_base::iostate flags = dataFile.rdstate();
        if (flags & ios::eofbit){
            dataFile.clear();
            return false;
        }
        else{
            std::string error;
            dataFile.clear();
            getline(dataFile,error);
            errorFile << error << std::endl;
        }
    }
     */
    return true;
}

template<typename T>
DataFileReader<T>::~DataFileReader() {

}
#endif //DT060G_DATAFILEREADER_H
