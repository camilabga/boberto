#include "Sensor.hpp"

Sensor::Sensor() {}

void Sensor::setPin(uint8_t _pin) {
  pin = _pin;
  pinMode(pin, INPUT);
}
