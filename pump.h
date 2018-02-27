#ifndef PUMP_H
#define PUMP_H

#include "point.h"
#include "step.h"
#include "game.h"
#include "dataucs.h"
#include "steppointer.h"
#include "pumpmode.h"

class Pump : Game
{
    StepPointer step; // step
    PumpMode mode; // single(5 keys) or double(10 keys) mode.
    DataUCS * rhythm; // step data

public:
    Pump();

    ~Pump();

    void toString(void);
};

#endif // PUMP_H
