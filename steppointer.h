#ifndef STEPPOINTER_H
#define STEPPOINTER_H

//#include "point.h"
//#include "step.h"
class Step;
class Point;

class StepPointer
{
    Step *** pstep;
    int height;
    int width;

public:
    StepPointer();
    StepPointer(int, int);
    //StepPointer(const StepPointer&);
    ~StepPointer();

    int getHeight() const { return height; }
    int getWidth() const { return width; }

    void operator=(StepPointer *);

    void setStep(const Point&, Step *);

    Step* operator[](const Point&);
    Step* operator[](const Point&) const;
};

#endif // STEPPOINTER_H
