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
        uint16_t red = 0, green = 0, blue = 0;

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

void ColorSensorAnalog::defineRanges() {
    changeColor(None);
    
    uint16_t red = 0, green = 0, blue = 0;

    changeColor(Red);
    delay(COLOR_DELAY);
    red = analogRead(analogPin);

    Serial.print("Red: ");
    Serial.println(red);
    
    changeColor(Green);
    delay(COLOR_DELAY);
    green = analogRead(analogPin);

    Serial.print("Green: ");
    Serial.println(green);

    changeColor(Blue);
    delay(COLOR_DELAY);
    blue = analogRead(analogPin);

    Serial.print("Blue: ");
    Serial.println(blue);

    changeColor(None);

    Serial.println();

    if (red > green and red > blue) 
        changeColor(Red); 
    else if (green > red and green > blue) 
        changeColor(Green);
    else if (blue > green and blue > red) 
        changeColor(Blue);
    else 
        changeColor(None);
}