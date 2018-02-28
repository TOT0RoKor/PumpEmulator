#include "fileio.h"

std::FILE * FileIO::in = NULL;

FileIO::FileIO()
{

}

size_t FileIO::readUcs(string& name, string * text) throw(string)
{

    if(!(in = std::fopen(name.c_str(), "r"))) throw "open error";

    char buf[128];
    while(std::fgets(buf, 127, in) != NULL) {
        *text += buf;
    }

    if(fclose(in)) throw "close error";

    return text->length();
}
