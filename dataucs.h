#ifndef DATAUCS_H
#define DATAUCS_H

#include "pump.h"

class DataUCS
{
    /* UCS File Datas */
    typedef double UMS; // millisecond
    double bpm; // beat per minute
    UMS delay; // delay
    unsigned int split; // 1 beat per split

    /* change rethm */
    unsigned int numInclusion; // number of beats splited about current rhythm
    DataUCS * next; // UCS data about information of next rhythm

public:
    DataUCS(double, UMS, unsigned int, unsigned int);

    void setNext(DataUCS *);
    DataUCS * getNext(void);

    friend void Pump::toString(); // Used Debugs
};

#endif // DATAUCS_H
