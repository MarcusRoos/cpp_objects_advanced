//
// Created by  on 2020-10-10.
//
// StudentID:
//

#ifndef DT060G_DATAFILEREADER_H
#define DT060G_DATAFILEREADER_H
#include "DataFilter.h"
#include <string>

template<typename T>
class DataFileReader {
public:
    DataFileReader(std::string aDataFileName, std::string aErrorFileName); /* pre: A file named aDataFile contains values to read. */
    ~DataFileReader(); /* post: Files are closed */
    void openFiles(); /* post: An input stream from the file named aDataFile and an output stream to the file named aErrorFile are opened. If either of these operations fails a runtime_error exception is thrown. */
    bool readNextValue(T &aValue); /* pre: openFiles has been successfully called. post: If a value has been successfully read, aValue holds that value and true is returned. Else, the read operation encountered an end-of-file and false is returned. */
private:
   // ... necessary members
};

#endif //DT060G_DATAFILEREADER_H
