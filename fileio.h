#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <string>
using std::string;
using std::size_t;

class FileIO
{
    File * in;
public:
    FileIO();
    static size_t read(string&, string*) throw (string); // file input
};

#endif // FILEIO_H
