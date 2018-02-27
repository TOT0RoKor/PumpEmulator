#include "step.h"

Step::Step(const unsigned char inst) : dot(inst)
{
}

Step::checkNZ() const
{
    return dot == 0 ? true : false;
}
