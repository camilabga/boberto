#ifndef COLORSENSORANALOG_HPP
#define COLORSENSORANALOG_HPP

#include <Arduino.h>
#include "Adafruit_NeoPixel.h"

#define NUM_SAMPLES 10
#define NUM_PIXELS 2
#define COLOR_DELAY 5

enum COLOR {
	Green, Blue, Red, None
};

class ColorSensorAnalog {
    private:
        uint8_t digitalPin;
        uint8_t analogPin;

        Adafruit_NeoPixel pixels;

    public:
        ColorSensorAnalog(uint8_t _digitalPin, uint8_t _analogPin);
        ~ColorSensorAnalog();

        void changeColor(COLOR color);
        COLOR readColor();
    
};

#endif // COLORSENSORANALOG_HPP