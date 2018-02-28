#ifndef PUMP_H
#define PUMP_H

#include <iostream>
#include "game.h"
#include "steppointer.h"
#include "pumpmode.h"
#include "loaducs.h"

using std::string;

class DataUCS;

class Pump : Game
{
    StepPointer step; // step
    PumpMode mode; // single(5 keys) or double(10 keys) mode.
    DataUCS * rhythm; // step data

public:
    Pump();

    void toString(void); // Used Debugs
//    PumpMode getMode() { return mode; }

    friend LoadUCS::LoadUCS(string, Pump*);
    friend DataUCS * LoadUCS::load(int, int, Pump*);
};

#endif // PUMP_H
