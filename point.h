#ifndef POINT_H
#define POINT_H

#include "loaducs.h"
#include "steppointer.h"

class Step;

//class StepPointer;

class Point
{
    int x;
    int y;
    int width;
public:
//    Point(int, int);
    Point(int, int, int =0);
    Point(const Point&);
    friend Step* StepPointer::operator[](const Point&);
    friend Step* StepPointer::operator[](const Point&) const;
    friend void StepPointer::setStep(const Point&, Step *);
    friend DataUCS* LoadUCS::load(int, int, Pump*);


//    int getx() const { return x; }
//    int gety() const { return y; }

    Point& operator++();
    Point& operator--();
    Point& operator++(int);
    Point& operator--(int);
};

#endif // POINT_H
