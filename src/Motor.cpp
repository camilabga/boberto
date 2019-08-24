#include "Motor.hpp"

Motor* Motor::instance0;
Motor* Motor::instance1;
Motor* Motor::instance2;
Motor* Motor::instance3;

Motor::Motor(uint8_t _whichISR) : whichISR(_whichISR) { cont = 0; }

Motor::~Motor() {}

void Motor::begin() {
    if (whichISR == 0) {
        instance0 = this;

        attachInterrupt(digitalPinToInterrupt(encoderPin), isr0, CHANGE);

    } else if (whichISR == 1) {
        instance1 = this;

        attachInterrupt(digitalPinToInterrupt(encoderPin), isr1, CHANGE);

    } else if (whichISR == 2) {
        instance2 = this;

        attachInterrupt(digitalPinToInterrupt(encoderPin), isr2, CHANGE);

    } else if (whichISR == 3) {
        instance3 = this;

        attachInterrupt(digitalPinToInterrupt(encoderPin), isr3, CHANGE);
    }
}

void Motor::isr0() { instance0->handleInterrupt(); }

void Motor::isr1() { instance1->handleInterrupt(); }

void Motor::isr2() { instance2->handleInterrupt(); }

void Motor::isr3() { instance3->handleInterrupt(); }

void Motor::handleInterrupt() {
    cont++;

    if (cont == goal) {
        cont = 0;
        stop();
    }
}

void Motor::setPins(uint8_t _encoderPin, uint8_t _pin1, uint8_t _pin2) {
    encoderPin = _encoderPin;
    pin1 = _pin1;
    pin2 = _pin2;

    pinMode(encoderPin, INPUT_PULLUP);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::forward(unsigned long int _goal) {
    cont = 0;
    goal = _goal;

    analogWrite(pin1, 255);
    analogWrite(pin2, 0);

    // Serial.println("Starting forward");
}

/* Interrupts are meanless here*/
void Motor::forward() {
    analogWrite(pin1, 255);
    analogWrite(pin2, 0);

    // Serial.println("Starting forward");
}

/* Interrupts are meanless here*/
void Motor::forward(uint8_t vel) {
    analogWrite(pin1, vel);
    analogWrite(pin2, vel);

    // Serial.println("Starting forward");
}

void Motor::backward(unsigned long int _goal) {
    cont = 0;
    goal = _goal;

    analogWrite(pin1, 0);
    analogWrite(pin2, 255);

    // Serial.println("Starting backward");
}

/* Interrupts are meanless here*/
void Motor::backward() {
    analogWrite(pin1, 0);
    analogWrite(pin2, 255);

    // Serial.println("Starting forward");
}

/* Interrupts are meanless here*/
void Motor::backward(uint8_t vel) {
    analogWrite(pin1, vel);
    analogWrite(pin2, vel);

    // Serial.println("Starting forward");
}

void Motor::stop() {
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
}