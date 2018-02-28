#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <string>
using std::string;
using std::size_t;

class FileIO
{
public:
    static std::FILE * in;

    FileIO();
    static size_t readUcs(string&, string*) throw (string); // file input
};

#endif // FILEIO_H
