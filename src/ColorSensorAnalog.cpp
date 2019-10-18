#include "ColorSensorAnalog.hpp"

ColorSensorAnalog::ColorSensorAnalog(uint8_t _digitalPin, uint8_t _analogPin) {
    digitalPin = _digitalPin;
    analogPin = _analogPin;

    pixels = Adafruit_NeoPixel(NUM_PIXELS, digitalPin, NEO_GBR + NEO_KHZ800);
    pixels.begin();
}

ColorSensorAnalog::~ColorSensorAnalog() {}

void ColorSensorAnalog::changeColor(COLOR color) {
    pixels.clear();

    for(uint8_t i = 0; i < NUM_PIXELS; i++) {
        switch (color) {
            case Red:
                pixels.setPixelColor(i, pixels.Color(0, 0, 255));
                break;
            
            case Green:
                pixels.setPixelColor(i, pixels.Color(0, 255, 0));
                break;

            case Blue:
                pixels.setPixelColor(i, pixels.Color(255, 0, 0));
                break;

            default:
                pixels.clear();
                break;
        }
    }

    pixels.show();
}

COLOR ColorSensorAnalog::readColor() {
    changeColor(None);

    uint8_t redCont = 0, greenCont = 0, blueCont = 0;

    for(uint8_t i = 0; i < NUM_SAMPLES; i++) {
        uint8_t red = 0, green = 0, blue = 0;

        changeColor(Red);
        delay(COLOR_DELAY);
        red = analogRead(analogPin);
        
        changeColor(Green);
        delay(COLOR_DELAY);
        green = analogRead(analogPin);

        changeColor(Blue);
        delay(COLOR_DELAY);
        blue = analogRead(analogPin);

        changeColor(None);

        if (red > green && red > blue) 
            redCont++;
        else if (green > red && green > blue) 
            greenCont++;
        else if (blue > red && blue > green) 
            blueCont++;
    }

    if (redCont > greenCont and redCont > blueCont) {
        changeColor(Red);
        return Red;
    } else if (greenCont > redCont and greenCont > blueCont) {
        changeColor(Green);
        return Green;
    } else if (blueCont > greenCont and blueCont > redCont) {
        changeColor(Blue);
        return Blue;
    } else 
        return None;
}