#include "gaminghandler.h"

GamingHandler::GamingHandler()
{
    game = new Pump();
}

void GamingHandler::show()
{
    game->toString();
}
