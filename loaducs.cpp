#include "loaducs.h"
#include "fileio.h"
#include "step.h"
#include <iostream>

using std::string::npos;

LoadUCS::LoadUCS(string name, Pump* pump) : name(name)
{
    try {
        FileIO::read(name, &text); // Read UCS File Data

        // mode of step
        string mode = getValueFromOption("Mode");
                /*text.assign(
                    text.find(
                        "=", text.find(":Mode")
                        )+1, 6
                    );*/
        if(mode.compare(string("Single"))) {
            pump->mode.keys = 5;
        }
        else if(mode.compare(string("Double"))) {
            pump->mode.keys = 10;
        }
        else throw "Mode error";


        // counting Line and Option of UCS file
        countLine = 0;
        countOption = 0;
        int curLine = -1;
        int nxtLine;
        while((nxtLine = text.find("\n", curLine+1)) != npos) {
            countLine++;
            int pos;
            if((pos = text.find(":", curLine+1)) != npos && pos < nxtLine)
                countOption++;
            curLine = nxtLine;
        }

        // pump step array allocation
        pump->step = new StepPointer(countLine - countOpiton, pump->mode.keys);

    } catch (string expn) {
        cout << "LoadUCS - " << name << " : " << expn << endl;
    }
}

/*
 * ucsPos : next read position of UCS file data
 * stepLine : next position of reference pump->step
 * stepPos : at work to read position about steps of current rhythm
 */
DataUCS * LoadUCS::load(int ucsPos, int stepLine, Pump* pump) const
{
    DataUCS * rhythm;

    int bpm = parseInt(getValueFromOption("BPM", ucsPos));
    int delay = parseInt(getValueFromOption("Delay", ucsPos));
    int split = parseInt(getValueFromOption("Split", ucsPos));

    int stepPos = text.find("\n", text.find(":split", ucsPos)+1) + 1;

//    for(int i=0; i<pump->step.getHeight(); i++) {
//        for(int j=0; j<pump->step.getWidth(); j++) {
//            unsigned char kind;
//            switch(text.at(stepPos)){
//            case '.':
//                kind = 0;
//                break;
//            case 'X':
//                kind = 1;
//                break;
//            case 'M':
//                kind = 2;
//                break;
//            case 'H':
//                kind = 3;
//                break;
//            case 'W':
//                kind = 4;
//                break;
//            default:
//                throw "step description error";
//            }
//            pump->step[Point(i, j)] = new Step(kind);
//            stepPos++;
//        }
//    }
    Point pos = new Point(stepLine, 0, pump->mode.keys);
    while(stepPos != ':' && stepPos != '\0') {
        unsigned char kind;
        switch(text.at(stepPos)){
        case '.':
            kind = 0;
            break;
        case 'X':
            kind = 1;
            break;
        case 'M':
            kind = 2;
            break;
        case 'H':
            kind = 3;
            break;
        case 'W':
            kind = 4;
            break;
        case '\n':
            stepPos++;
            continue;
        default:
            throw "step description error";
        }
        pump->step[pos] = new Step(kind);
        pos++;
        stepPos++;
    }

    int numInclusion = pos.x - stepLine;

    rhythm = new DataUCS(bpm, delay, split, numInclusion);
    if(stepPos == ':') {
        rhythm->nextRhythm() = load(stepPos, pos.x, pump);
    }
    return rhythm;
}

string LoadUCS::getValueFromOption(string opt, int ucsPos)
{
    int startPos;
    int endPos;
    return text.assign(
                (startPos = text.find(
                    "=", text.find(":"+opt, ucsPos)
                    )+1), (endPos = text.find("\n" , startPos)) - startPos
                );
}

int LoadUCS::parseInt(string str)
{
    int result=0;
    for(int i; i<str.length(); i++) {
        result *= 10;
        result += str.at(i) - '0';
    }
}
