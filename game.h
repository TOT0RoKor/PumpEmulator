#ifndef GAME_H
#define GAME_H

/*
 * abstract class.
 */

class Game
{
public:
    virtual Game();
    virtual ~Game();
    virtual void toString(void) = 0;
};

#endif // GAME_H
