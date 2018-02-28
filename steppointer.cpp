#include "steppointer.h"
#include "point.h"

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

void StepPointer::setStep(const Point& pos, Step * ref) {
    if(0 <= pos.x && pos.x < height && 0 <= pos.y && pos.y < width)
       pstep[pos.x][pos.y] = ref;
}

Step* StepPointer::operator[](const Point& pos){
    if(0 <= pos.x && pos.x < height && 0 <= pos.y && pos.y < width)
        return pstep[pos.x][pos.y];
    else
        return NULL;
}

Step* StepPointer::operator[](const Point& pos) const{
    if(0 <= pos.x && pos.x < height && 0 <= pos.y && pos.y < width)
        return pstep[pos.x][pos.y];
    else
        return NULL;
}

//StepPointer::StepPointer(const StepPointer& ref)
//    : height(ref.height), width(ref.width)
//{
//    pstep = new Step**[this->height];
//    for(int i=0; i<this->height; i++) {
//        pstep[i] = new Step*[this->width];
//    }

//}

void StepPointer::operator=(StepPointer * ref) {
    height = ref->height;
    width = ref->width;
    pstep = new Step**[this->height];
    for(int i=0; i<this->height; i++) {
        pstep[i] = new Step*[this->width];
    }
}


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
