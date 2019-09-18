#include "LineSensor.hpp"

LineSensor::LineSensor() {}

void LineSensor::setPin(uint8_t _pin) {
    pin = _pin;
    pinMode(pin, INPUT);
}

uint8_t LineSensor::getValue() { 
    return digitalRead(pin); 
}