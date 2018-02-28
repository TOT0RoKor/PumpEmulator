#include "steppointer.h"

StepPointer::StepPointer()
{

}
StepPointer::StepPointer(int height, int width)
    : height(height), width(width)
{
    pstep = new Step**[this->height];
    for(int i=0; i<this->height; i++) {
        pstep[i] = new Step*[this->width];
    }

}

void StepPointer::setStep(Point pos, Step * ref) {
    if(0 <= pos.getx() && pos.getx() < height && 0 <= pos.gety() && pos.gety() < width)
       pstep[pos.getx()][pos.gety()] = ref;
}

//StepPointer::StepPointer(const StepPointer& ref)
//    : height(ref.height), width(ref.width)
//{
//    pstep = new Step**[this->height];
//    for(int i=0; i<this->height; i++) {
//        pstep[i] = new Step*[this->width];
//    }

//}


StepPointer::~StepPointer()
{
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            delete pstep[i][j];
        }
        delete[] pstep[i];
    }
    delete[] pstep;
}
