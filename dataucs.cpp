#include "dataucs.h"

DataUCS::DataUCS(unsigned int bpm, UMS delay, unsigned int split, unsigned int numInclusion)
    : bpm(bpm), delay(delay), split(split), numInclusion(numInclusion)
{

}

DataUCS * DataUCS::nextRhythm(void)
{
    return next;
}
