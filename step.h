#ifndef STEP_H
#define STEP_H


class Step
{
    unsigned char dot; // step data
    /*
     * 0 : .
     * 1 : X
     * 2 : M
     * 3 : H
     * 4 : W
     */
public:
    Step(const unsigned char inst); // step initialize
    //explicit Step(const Step& ref);

    unsigned char getDot(void);
    bool checkNZ(void) const; // check step data for not zero

};

#endif // STEP_H
