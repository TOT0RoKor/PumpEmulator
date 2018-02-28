#include "dataucs.h"

DataUCS::DataUCS(double bpm, UMS delay, unsigned int split, unsigned int numInclusion)
    : bpm(bpm), delay(delay), split(split), numInclusion(numInclusion)
{

}

void DataUCS::setNext(DataUCS * ref)
{
    next = ref;
}

DataUCS * DataUCS::getNext(void)
{
    return next;
}
