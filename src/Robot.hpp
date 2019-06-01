#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Arduino.h"

class Motor {
    public: 
        int encoderPin;
        int pin1, pin2;

        volatile long int cont;
        int goal;

        int side;
    
    
        Motor();
        ~Motor();

        void setupInterruptHandler(void (*ISR)(void), int value);
        void handleInterrupt(void);

        void setPins(int _encoderPin, int _pin1, int _pin2);
        void forward(long int goal);
        void stop();
};

class Robot {
    public:
        Motor frontLeft, frontRight, backLeft, backRight;
        
        Robot();
        
        void forward(long int goal);

        ~Robot();

};

#endif // ROBOT_HPP