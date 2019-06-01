#include "Robot.hpp"

Motor::Motor() {}

Motor::~Motor() {}

void Motor::setupInterruptHandler(void (*ISR)(void), int value) {
    attachInterrupt(
        digitalPinToInterrupt(this->encoderPin),
        ISR,
        value
    );
}

void Motor::handleInterrupt(void) {
    this->cont += 1;

    if (this->cont == this->goal) {
        this->cont = 0;
        this->stop();
    }
}

void Motor::setPins(int _encoderPin, int _pin1, int _pin2) {
    this->encoderPin = _encoderPin;
    this->pin1 = _pin1;
    this->pin2 = _pin2;

    pinMode(this->encoderPin, INPUT_PULLUP);
    pinMode(this->pin1, OUTPUT);
    pinMode(this->pin2, OUTPUT);
}

void Motor::forward(long int _goal) {
    this->side = 1;
    this->cont = 0;
    this->goal = _goal;

    digitalWrite(this->pin1, HIGH);
    digitalWrite(this->pin2, LOW);

    Serial.println("Starting forward");
}

void Motor::stop() {
    digitalWrite(this->pin1, LOW);
    digitalWrite(this->pin2, LOW);
}

Robot::Robot() {
    // Inicia os pinos dos motores
    this->frontLeft.setPins(2, 5, 4);
    this->frontRight.setPins(3, 6, 7);
    this->backLeft.setPins(18, 8, 9);
    this->backRight.setPins(19, 10, 11);
}

void Robot::forward(long int goal) {
    frontLeft.forward(goal);
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.forward(goal);
}

Robot::~Robot() {}