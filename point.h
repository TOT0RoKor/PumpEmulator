#ifndef POINT_H
#define POINT_H

#include "pump.h"
#include "loaducs.h"

class Point
{
    int x;
    int y;
    int width;
public:
    Point(int, int, int);
    friend Step* Pump::operator[](Point&);
    friend DataUCS * LoadUCS::load(int, int, Pump*) const;

    Point& operator++();
    Point& operator--();
    Point& operator++(int);
    Point& operator--(int);
};

#endif // POINT_H
