#include "point.h"

//Point::Point(int x, int y) : x(x), y(y), width(0)
//{

//}

Point::Point(int x, int y, int width) : x(x), y(y), width(width)
{

}

Point::Point(const Point& ref) : x(ref.x), y(ref.y), width(ref.width)
{

}

Point& Point::operator++()
{
    if(width == 0) throw "Point op ++ error : width == 0";
    x += 1;
    return *this;
}

Point& Point::operator--()
{
    if(width == 0) throw "Point op -- error : width == 0";
    x -= 1;
    return *this;
}

Point& Point::operator++(int)
{
    if(width == 0) throw "Point op ++i error : width == 0";
    y += 1;
    if(y == width) {
        y = 0;
        x += 1;
    }
    return *this;
}

Point& Point::operator--(int)
{
    if(width == 0) throw "Point op --i error : width == 0";
    y -= 1;
    if(y == -1) {
        y = width-1;
        x -= 1;
    }
    return *this;
}
