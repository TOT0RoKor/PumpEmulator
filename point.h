#ifndef POINT_H
#define POINT_H

#include "loaducs.h"
//#include "steppointer.h"

class Step;

class Point
{
    int x;
    int y;
    int width;
public:
    Point(int, int);
    Point(int, int, int);
    Point(const Point& ref) : x(ref.x), y(ref.y), width(ref.width){}
//    friend Step* StepPointer::operator[](Point);
//    friend Step* StepPointer::operator[](Point) const;
    friend DataUCS* LoadUCS::load(int, int, Pump*);


    int getx() const { return x; }
    int gety() const { return y; }

    Point& operator++();
    Point& operator--();
    Point& operator++(int);
    Point& operator--(int);
};

#endif // POINT_H
