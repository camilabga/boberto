#include "Claw.hpp"

Claw::Claw(uint8_t _setPin, uint8_t _dirPin, uint8_t _motorPin1, uint8_t _motorPin2) {
    setPin = _setPin;
    dirPin = _dirPin;
    motorPin1 = _motorPin1;
    motorPin2 = _motorPin2;

    pinMode(setPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
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

void Claw::goHome() {
    digitalWrite(dirPin, LOW);

    for(int i = 0; i < 12800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }

    height = 0;
}

void Claw::goToContainer(uint8_t container) {
    if(container > height)
        digitalWrite(dirPin, LOW);
    else
        digitalWrite(dirPin, HIGH);
    
    for(int i = 0; i < 3200 * abs(container - height); i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }
}

void Claw::extend() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
}

void Claw::retract() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
}