#ifndef STEPPOINTER_H
#define STEPPOINTER_H

#include "point.h"
#include "step.h"

class StepPointer
{
    Step *** step;
    const unsigned int height;
    const unsigned int width;

public:
    StepPointer(const unsigned int, const unsigned int);
    ~StepPointer();

    const unsigned int getHeight() const { return height; }
    const unsigned int getWidth() const { return width; }

    Step* StepPointer::operator[](Point&);
    Step* StepPointer::operator[](Point&) const;
};

#endif // STEPPOINTER_H
