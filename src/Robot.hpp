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
       
        void forward(long int _goal);
        void backward(long int _goal);
        void stop();
};

class Robot {
    public:
        Motor frontLeft, frontRight, backLeft, backRight;
        
        Robot();

        void forward(long int goal); 
        void backward(long int goal);
        void sidewaysRight(long int goal);
        void sidewaysLeft(long int goal);
        void rotateLeft(long int goal);
        void rotateRight(long int goal);
        void moveRightForward(long int goal);
        void moveRightBackward(long int goal);
        void moveLeftForward(long int goal);
        void moveLeftBackward(long int goal);

        ~Robot();
};

#endif // ROBOT_HPP