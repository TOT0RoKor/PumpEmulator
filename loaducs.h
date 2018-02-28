#ifndef LOADUCS_H
#define LOADUCS_H

//#include "pump.h"
//#include "dataucs.h"
class DataUCS;
class Pump;

#include <string>
using std::string;

/*
 * Only Used Temporary Object
 */

class LoadUCS
{
    /* UCS File option Delimiter */
    const static char DELIMITER_OPTION = ':';
    const static char DELIMITER_VALUE = '=';

    //string getValueFromOption(string);
    string getValueFromOption(string, int ucsPos=0);
    int parseInt(string);
    double parseDouble(string);

    /* UCS file */
    string name;
    string text;

    /* UCS file */

public:
    LoadUCS(string, Pump*);
    DataUCS * load(int, int, Pump*);
};

#endif // LOADUCS_H
