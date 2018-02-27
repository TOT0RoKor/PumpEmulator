#include "steppointer.h"

StepPointer::StepPointer(const unsigned int height, const unsigned int width)
    : height(height), width(width)
{
    step = new Step**[this->height];
    for(int i=0; i<this->height; i++) {
        step[i] = new Step*[this->width];
    }

}

StepPointer::~StepPointer()
{
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            delete step[i][j];
        }
        delete[] step[i];
    }
    delete[] step;
}


Step* StepPointer::operator[](const Point& ref)
{
    if(0 <= ref.x && ref.x < height && 0 <= ref.y && ref.y < width)
        return step[ref.x][ref.y];
}

Step* StepPointer::operator[](const Point& ref) const
{
    if(0 <= ref.x && ref.x < height && 0 <= ref.y && ref.y < width)
        return step[ref.x][ref.y];
}
