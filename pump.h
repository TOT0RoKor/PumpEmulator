#ifndef PUMP_H
#define PUMP_H

#include "point.h"
#include "step.h"
#include "game.h"
#include "steppointer.h"
#include "pumpmode.h"

class DataUCS;
class LoadUCS;

class Pump : Game
{
    StepPointer step; // step
    PumpMode mode; // single(5 keys) or double(10 keys) mode.
    DataUCS * rhythm; // step data

public:
    Pump();

    void toString(void);
//    PumpMode getMode() { return mode; }

    friend LoadUCS::LoadUCS(string name, Pump* pump);
    friend DataUCS * LoadUCS::load(int, int, Pump*);
};

#endif // PUMP_H
