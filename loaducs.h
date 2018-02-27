#ifndef LOADUCS_H
#define LOADUCS_H

#include "pump.h"
#include "dataucs.h"
#include <string>
using std::string;

/*
 * Only Used Temporary Object
 */

class LoadUCS
{
    /* UCS File option Delimiter */
    static const char DELIMITER_OPTION = ':';
    static const char DELIMITER_VALUE = '=';

    string getValueFromOption(string, int);
    int parseInt(string);

    /* UCS file */
    string name;
    string text;

    /* UCS file */

public:
    LoadUCS(string, Pump*);
    DataUCS * load(int, int, Pump*) const;
};

#endif // LOADUCS_H
