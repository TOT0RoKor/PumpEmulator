#include "dataucs.h"

DataUCS::DataUCS(double bpm, UMS delay, unsigned int split, unsigned int numInclusion)
    : bpm(bpm), delay(delay), split(split), numInclusion(numInclusion)
{

}

void DataUCS::nextRhythm(DataUCS * ref)
{
    next = ref;
}
