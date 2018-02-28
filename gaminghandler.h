#ifndef GAMINGHANDLER_H
#define GAMINGHANDLER_H

#include "pump.h"
#include "game.h"

class GamingHandler
{
    Pump * game;
public:
    GamingHandler();

    void show(void);
};

#endif // GAMINGHANDLER_H
