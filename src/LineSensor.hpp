#ifndef LINESENSOR_HPP
#define LINESENSOR_HPP

#include <Arduino.h>

class LineSensor {
    private:
        uint8_t pin, value;
        bool analog;

    public:
        LineSensor();
        void setPin(uint8_t _pin);
        uint8_t getValue();
};

#endif  // LINESENSOR_HPP