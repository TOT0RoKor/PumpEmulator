#ifndef GAMINGHANDLER_H
#define GAMINGHANDLER_H

#include "pump.h"
#include "game.h"

class GamingHandler
{
    Game * game;
public:
    GamingHandler();
    ~GamingHandler();

    void show(void);
};

#endif // GAMINGHANDLER_H
