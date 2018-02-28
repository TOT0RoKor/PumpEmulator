#include "pump.h"
#include "point.h"
#include "step.h"
#include <QDebug>
#include "dataucs.h"
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
    DataUCS * curRhm = rhythm;
    while(curRhm != NULL) {
        qDebug() << "/ bpm : " << curRhm->bpm << "/ delay : " << curRhm->delay << "/ split : "
                 << curRhm->split << "numIncl : " << curRhm->numInclusion;
        curRhm = curRhm->next;
    }
}
