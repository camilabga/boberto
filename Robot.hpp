#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "Arduino.h"

struct  Motor {
    int encoderPin;
    int pin1, pin2;
};


class Robot {
    private:
        Motor frontLeft, frontRight, backLeft, backRight;

    public:
        Robot();
        
        void forward();

        ~Robot();

};


#endif // ROBOT_HPP