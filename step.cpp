#include "step.h"

Step::Step(const unsigned char inst) : dot(inst)
{
}

bool Step::checkNZ() const
{
    return dot == 0 ? true : false;
}

unsigned char Step::getDot(void)
{
    return dot;
}
