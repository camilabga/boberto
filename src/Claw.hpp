#ifndef CLAW_H
#define CLAW_H

#include <Arduino.h>

class Claw {
    private:
        uint8_t setPin; 
        uint8_t dirPin;

    public:
        Claw(uint8_t _setPin, uint8_t _dirPin);
        ~Claw();

        void goUp();
        void goDown();
    
};

#endif // CLAW_H