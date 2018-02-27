#include "pump.h"
#include "loaducs.h"
#include <iostream>
using namespace std;

Pump::Pump()
{
    rhythm = LoadUCS("CS051.ucs", this).load(0, 0, this);
}

Pump::~Pump()
{

}

void Pump::toString()
{
    for(int i=0; i<step.getHeight(); i++){
        for(int j=0; j<step.getWidth(); j++){
            cout << step[Point(i, j)]->getDot();
        }
        cout << endl;
    }
}
