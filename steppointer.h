#ifndef STEPPOINTER_H
#define STEPPOINTER_H

#include "point.h"
//#include "step.h"
class Step;

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

    Step& operator=(StepPointer * ref) {
        height = ref->getHeight();
        width = ref->getWidth();
        pstep = new Step**[this->height];
        for(int i=0; i<this->height; i++) {
            pstep[i] = new Step*[this->width];
        }
    }

    void setStep(Point, Step *);

    Step* operator[](Point pos){
        if(0 <= pos.getx() && pos.getx() < height && 0 <= pos.gety() && pos.gety() < width)
            return pstep[pos.getx()][pos.gety()];
        else
            return NULL;
    }
};

#endif // STEPPOINTER_H
