#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "Arduino.h"
class Sensor {
   private:
    uint8_t pin, value;
    bool analog;

   public:
    Sensor();
    void setPin(uint8_t _pin);
    inline uint8_t getValue() { return digitalRead(pin); }
};

class Sharp {
   public:
    Sharp();
    inline uint8_t getValue(uint8_t pin) { return analogRead(pin); }
};

#endif  // SENSOR_HPP