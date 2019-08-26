#include "Claw.hpp"

Claw::Claw(uint8_t _setPin, uint8_t _dirPin) {
    setPin = _setPin;
    dirPin = _dirPin;
        
    pinMode(setPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

Claw::~Claw() {}

void Claw::goUp() {
    digitalWrite(dirPin, HIGH);

    for(int i = 0; i < 12800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }

}

void Claw::goDown() {
    digitalWrite(dirPin, LOW);

    for(int i = 0; i < 12800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }
    
}