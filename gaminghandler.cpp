#include "gaminghandler.h"
#include "pump.h"

GamingHandler::GamingHandler()
{
    game = new Pump();
}

void GamingHandler::show()
{
    game->toString(); // Used Debugs

}
