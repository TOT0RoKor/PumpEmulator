#include "fileio.h"

FileIO::FileIO()
{

}

static size_t FileIO::read(string& name, string * text)
{

    if(!(in = fopen(name, "r"))) throw "open error";

    char buf[128];
    while(std::fgets(buf, 127, out) != EOF) {
        *text += buf;
    }

    if(fclose(out)) throw "close error";

    return text->length();
}
