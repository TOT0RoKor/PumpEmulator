#include "pump.h"
#include "loaducs.h"
#include <QDebug>
using namespace std;

Pump::Pump()
{
    rhythm = LoadUCS("CS051.ucs", this).load(0, 0, this);
}


void Pump::toString()
{
    for(int i=0; i<step.getHeight(); i++){
        string arr="";
        for(int j=0; j<step.getWidth(); j++){
            arr += step[Point(i, j)]->getDot() + '0';
        }
        qDebug() << arr.c_str();
    }
}
