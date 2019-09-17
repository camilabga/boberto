#include "Claw.hpp"

#define MOTOR_TIME 2500
#define PERIODO 40

Claw::Claw(uint8_t _setPin, uint8_t _dirPin, uint8_t _motorPin1,
           uint8_t _motorPin2, uint8_t _endStopPin) {
    setPin = _setPin;
    dirPin = _dirPin;
    motorPin1 = _motorPin1;
    motorPin2 = _motorPin2;
    endStopPin = _endStopPin;

    pinMode(setPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);

    pinMode(endStopPin, INPUT_PULLUP);
}

Claw::~Claw() {}

void Claw::goUp() {
    digitalWrite(dirPin, HIGH);

    for (int i = 0; i < 12800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }
}

void Claw::goDown() {
    digitalWrite(dirPin, LOW);

    for (int i = 0; i < 12800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }
}

void Claw::goHome() {
    digitalWrite(dirPin, LOW);

    while (digitalRead(endStopPin)) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }

    height = 1;
}

void Claw::goToContainer(float container) {
    if (container > 5.5) return;

    if (container > height)
        digitalWrite(dirPin, HIGH);
    else
        digitalWrite(dirPin, LOW);

    for (int i = 0; i < 3200 * abs(container - height); i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(25);
        digitalWrite(setPin, LOW);
        delayMicroseconds(25);
    }

    height = container;
}

void Claw::extend() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1100);
    stop();
}

void Claw::retract() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay((3 * MOTOR_TIME) / 4);
    stop();
}

void Claw::ajustContainer() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(250);
    stop();
}

void Claw::stop() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
}