#include "Claw.hpp"

#define SPEED 20
#define MICRO_STEP 16
#define AJUST_FORWARD 1100
#define AJUST_BACKWARD 600

Claw::Claw(uint8_t _setPin, uint8_t _dirPin, uint8_t _enable,uint8_t _motorPin1, uint8_t _motorPin2, uint8_t _endStopPin) {
    setPin = _setPin;
    dirPin = _dirPin;
    enable = _enable;
    motorPin1 = _motorPin1;
    motorPin2 = _motorPin2;
    endStopPin = _endStopPin;

    pinMode(setPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    pinMode(enable, OUTPUT);
    digitalWrite(enable, LOW);

    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);

    pinMode(endStopPin, INPUT);
}

Claw::~Claw() {}

void Claw::goUp() {
    digitalWrite(dirPin, HIGH);

    for (uint16_t i = 0; i < MICRO_STEP * 800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(SPEED);
        digitalWrite(setPin, LOW);
        delayMicroseconds(SPEED);
    }
}

void Claw::goDown() {
    digitalWrite(dirPin, LOW);

    for (uint16_t i = 0; i < MICRO_STEP * 800; i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(SPEED);
        digitalWrite(setPin, LOW);
        delayMicroseconds(SPEED);
    }
}

void Claw::goHome() {
    digitalWrite(dirPin, LOW);

    while (!digitalRead(endStopPin)) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(SPEED);
        digitalWrite(setPin, LOW);
        delayMicroseconds(SPEED);
    }

    height = 1.0f;
}

void Claw::goToContainer(float container) {
    if (container > 5.5) return;

    if (container > height)
        digitalWrite(dirPin, HIGH);
    else
        digitalWrite(dirPin, LOW);

    for (uint16_t i = 0; i < MICRO_STEP * 200 * abs(container - height); i++) {
        digitalWrite(setPin, HIGH);
        delayMicroseconds(SPEED);
        digitalWrite(setPin, LOW);
        delayMicroseconds(SPEED);
    }

    height = container;
}

void Claw::extend() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(800);
    stop();
}

void Claw::retract() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(AJUST_FORWARD + AJUST_BACKWARD);
    stop();
}

void Claw::ajustContainer() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1000);
    stop();

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(600);
    stop();
}

void Claw::stop() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
}