#include "loaducs.h"
#include "fileio.h"
#include "step.h"
#include <iostream>
#include "pump.h"
#include "dataucs.h"
#include <QDebug>
#include "point.h"

using std::string;
//using std::__cxx11::string::npos;

LoadUCS::LoadUCS(string name, Pump* pump) : name(name)
{
    try {
        FileIO::readUcs(name, &text); // Read UCS File Data

        // mode of step
        string mode = getValueFromOption("Mode");
                /*text.assign(
                    text.find(
                        "=", text.find(":Mode")
                        )+1, 6
                    );*/
        if(!mode.compare(string("Single"))) {
            pump->mode.keys = 5;
        }
        else if(!mode.compare(string("Double"))) {
            pump->mode.keys = 10;
        }
        else throw "Mode error";


        // counting Line and Option of UCS file
        int countLine = 0;
        int countOption = 0;
        int curLine = -1;
        int nxtLine;
        while((nxtLine = text.find("\n", curLine+1)) != -1) {
            countLine++;
            int pos;
            if((pos = text.find(DELIMITER_OPTION, curLine+1)) != -1 && pos < nxtLine)
                countOption++;
            curLine = nxtLine;
        }

        // pump step array allocation
        pump->step = new StepPointer(countLine - countOption, pump->mode.keys);

    } catch (string expn) {
        qDebug() << "LoadUCS - " << name.c_str() << " : " << expn.c_str();
    }
}

/*
 * ucsPos : next read position of UCS file data
 * stepLine : next position of reference pump->step
 * stepPos : at work to read position about steps of current rhythm
 */
DataUCS * LoadUCS::load(int ucsPos, int stepLine, Pump* pump)
{
    DataUCS * rhythm;

    double bpm = parseDouble(getValueFromOption("BPM", ucsPos));
    double delay = parseDouble(getValueFromOption("Delay", ucsPos));
    int split = parseInt(getValueFromOption("Split", ucsPos));

    int stepPos = text.find("\n", text.find(":Split", ucsPos)+1) + 1;

    Point * pos = new Point(stepLine, 0, pump->mode.keys);
    while((text.at(stepPos) != ':' && pump->step.getHeight() >= pos->x + 1)) {
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
        pump->step.setStep(*pos, new Step(kind));
        (*pos)++;
        stepPos++;

    }

    int numInclusion = pos->x - stepLine;

    rhythm = new DataUCS(bpm, delay, split, numInclusion);
    if(text.at(stepPos) == ':') {
        rhythm->setNext(load(stepPos, pos->x, pump));
    }
    else {
        rhythm->setNext(NULL);
    }
    return rhythm;
}

string LoadUCS::getValueFromOption(string opt, int ucsPos)
{
    int startPos = text.find(DELIMITER_VALUE, text.find(DELIMITER_OPTION+opt, ucsPos))+1;
    int endPos = text.find("\n" , startPos);
    return text.substr(startPos, endPos - startPos);
}

int LoadUCS::parseInt(string str)
{
    int result=0;
    for(int i=0; i<str.length(); i++) {
        result *= 10;
        result += str.at(i) - '0';
    }
    return result;
}
double LoadUCS::parseDouble(string str)
{
    bool upperDot = true;
    double result=0;
    int k=0;
    for(int i=0; i<str.length(); i++) {
        if(str.at(i) == '.') {
            upperDot = false;
            continue;
        }
        if(upperDot) {
            result *= 10;
            result += str.at(i) - '0';
        }
        else {
            k++;
            double temp = 1;
            for(int j=0; j<k; j++) {
                temp /= 10;
            }
            result += temp * (str.at(i) - '0');
        }
    }
    return result;
}
