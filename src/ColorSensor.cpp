#include "ColorSensor.hpp"

ColorSensor::ColorSensor(uint8_t _ledPin) : ledPin(_ledPin) {}

void ColorSensor::init() {
    pinMode(ledPin, OUTPUT);

    colorCap[0] = 9;
    colorCap[1] = 9;
    colorCap[2] = 2;
    colorCap[3] = 5;

    colorInt[0] = 2048;
    colorInt[1] = 2048;
    colorInt[2] = 2048;
    colorInt[3] = 2048;

    /*
        Sensor gain registers, CAP_... to select number of capacitors.
        value must be <= 15
    */
    writeRegister(colorCap[RED] & 0xF, CAP_RED);
    writeRegister(colorCap[GREEN] & 0xF, CAP_GREEN);
    writeRegister(colorCap[BLUE] & 0xF, CAP_BLUE);
    writeRegister(colorCap[CLEAR] & 0xF, CAP_CLEAR);

    /*
        Write sensor gain registers INT_...
        to select integration time value must be <= 4096
    */
    writeRegister((unsigned char)colorInt[RED], INT_RED_LO);
    writeRegister((unsigned char)((colorInt[RED] & 0x1FFF) >> 8), INT_RED_HI);
    writeRegister((unsigned char)colorInt[BLUE], INT_BLUE_LO);
    writeRegister((unsigned char)((colorInt[BLUE] & 0x1FFF) >> 8), INT_BLUE_HI);
    writeRegister((unsigned char)colorInt[GREEN], INT_GREEN_LO);
    writeRegister((unsigned char)((colorInt[GREEN] & 0x1FFF) >> 8),
                  INT_GREEN_HI);
    writeRegister((unsigned char)colorInt[CLEAR], INT_CLEAR_LO);
    writeRegister((unsigned char)((colorInt[CLEAR] & 0x1FFF) >> 8),
                  INT_CLEAR_HI);
}

void ColorSensor::calibrate() {
    delay(2);
    calibrateColor();
    calibrateClear();
    calibrateCapacitors();
}

void ColorSensor::ledOn() { digitalWrite(ledPin, HIGH); }

void ColorSensor::ledOff() { digitalWrite(ledPin, LOW); }

int ColorSensor::calibrateClear() {
    int gainFound = 0;
    int upperBox = 4096;
    int lowerBox = 0;
    int half;

    while (!gainFound) {
        half = ((upperBox - lowerBox) / 2) + lowerBox;

        if (half == lowerBox)
            gainFound = 1;
        else {
            writeInt(INT_CLEAR_LO, half);
            performMeasurement();
            int halfValue = readRegisterInt(DATA_CLEAR_LO);

            if (halfValue > 1000)
                upperBox = half;
            else if (halfValue < 1000)
                lowerBox = half;
            else
                gainFound = 1;
        }
    }

    return half;
}

int ColorSensor::calibrateColor() {
    int gainFound = 0;
    int upperBox = 4096;
    int lowerBox = 0;
    int half;

    while (!gainFound) {
        half = ((upperBox - lowerBox) / 2) + lowerBox;

        if (half == lowerBox)
            gainFound = 1;
        else {
            writeInt(INT_RED_LO, half);
            writeInt(INT_GREEN_LO, half);
            writeInt(INT_BLUE_LO, half);

            performMeasurement();
            int halfValue = 0;

            halfValue = max(halfValue, readRegisterInt(DATA_RED_LO));
            halfValue = max(halfValue, readRegisterInt(DATA_GREEN_LO));
            halfValue = max(halfValue, readRegisterInt(DATA_BLUE_LO));

            if (halfValue > 1000)
                upperBox = half;
            else if (halfValue < 1000)
                lowerBox = half;
            else
                gainFound = 1;
        }
    }

    return half;
}

void ColorSensor::calibrateCapacitors() {
    int calibrationRed = 0;
    int calibrationBlue = 0;
    int calibrationGreen = 0;
    int calibrated = 0;

    int oldDiff = 5000;

    while (!calibrated) {
        /*
            sensor gain setting (Avago app note 5330)
            CAPs are 4bit (higher value will result in lower output)
        */
        writeRegister(calibrationRed, CAP_RED);
        writeRegister(calibrationGreen, CAP_GREEN);
        writeRegister(calibrationBlue, CAP_BLUE);

        // int colorGain = _calibrateColorGain();
        int colorGain = readRegisterInt(INT_RED_LO);
        writeInt(INT_RED_LO, colorGain);
        writeInt(INT_GREEN_LO, colorGain);
        writeInt(INT_BLUE_LO, colorGain);

        int maxRead = 0;
        int minRead = 4096;
        int red = 0;
        int green = 0;
        int blue = 0;

        for (int i = 0; i < 4; i++) {
            performMeasurement();
            red += readRegisterInt(DATA_RED_LO);
            green += readRegisterInt(DATA_GREEN_LO);
            blue += readRegisterInt(DATA_BLUE_LO);
        }

        red /= 4;
        green /= 4;
        blue /= 4;

        maxRead = max(maxRead, red);
        maxRead = max(maxRead, green);
        maxRead = max(maxRead, blue);

        minRead = min(minRead, red);
        minRead = min(minRead, green);
        minRead = min(minRead, blue);

        int diff = maxRead - minRead;

        if (oldDiff != diff) {
            if ((maxRead == red) && (calibrationRed < 15))
                calibrationRed++;
            else if ((maxRead == green) && (calibrationGreen < 15))
                calibrationGreen++;
            else if ((maxRead == blue) && (calibrationBlue < 15))
                calibrationBlue++;
        } else
            calibrated = 1;

        oldDiff = diff;

        int rCal = calibrationRed;
        int gCal = calibrationGreen;
        int bCal = calibrationBlue;
    }
}

void ColorSensor::writeInt(int address, int gain) {
    if (gain < 4096) {
        byte msb = gain >> 8;
        byte lsb = gain;

        writeRegister(lsb, address);
        writeRegister(msb, address + 1);
    }
}

void ColorSensor::performMeasurement() {
    writeRegister(0x01, 0x00);  // start sensing
    while (readRegister(0x00) != 0)
        ;  // waiting for a result
}

void ColorSensor::getOffset() {
    digitalWrite(ledPin, LOW);
    delay(10);

    // Start sensing
    writeRegister(0x02, 0x00);
    while (readRegister(0x00) != 0)
        ;  // waiting for a result
    // writeRegister(0x01, 0x01);  // set trim
    // delay(100);

    for (int i = 0; i < 4; i++)
        colorOffset[i] = (signed char)readRegister(OFFSET_RED + i);

    digitalWrite(ledPin, HIGH);
}

void ColorSensor::writeRegister(unsigned char data, unsigned char address) {
    Wire.beginTransmission(ADJD_S311_ADDRESS);
    Wire.write(address);
    Wire.write(data);
    Wire.endTransmission();
}

unsigned char ColorSensor::readRegister(unsigned char address) {
    unsigned char data;

    Wire.beginTransmission(ADJD_S311_ADDRESS);
    Wire.write(address);
    Wire.endTransmission();

    Wire.requestFrom(ADJD_S311_ADDRESS, 1);
    while (!Wire.available())
        ;  // wait till we can get data

    return Wire.read();
}

int ColorSensor::readRegisterInt(unsigned char address) {
    return readRegister(address) + (readRegister(address + 1) << 8);
}

RGBC ColorSensor::read() {
    // Read data registers and return a RGBC var
    RGBC color = RGBC();

    performMeasurement();

    color.red = readRegisterInt(DATA_RED_LO);
    color.green = readRegisterInt(DATA_GREEN_LO);
    color.blue = readRegisterInt(DATA_BLUE_LO);
    color.clear = readRegisterInt(DATA_CLEAR_LO);

    return color;
}

COLOR ColorSensor::readColor() {
    RGBC color;
    byte red = 0, green = 0, blue = 0;

    for (byte i = 0; i < 20; i++) {
        color = read();

        if (color.red > color.blue and color.red > color.green)
            red++;
        else if (color.green > color.red and color.green > color.blue)
            green++;
        else if (color.blue > color.red and color.blue > color.green)
            blue++;
        else
            continue;

        delay(10);
    }
    /*
    Serial.print("\nInside Class COLOR: ");
    Serial.print(color.red);
    Serial.print(" ");
    Serial.print(color.green);
    Serial.print(" ");
    Serial.print(color.blue);

    Serial.print("\nInside Class RGB: ");
    Serial.print(red);
    Serial.print(" ");
    Serial.print(green);
    Serial.print(" ");
    Serial.print(blue);
    Serial.print("\n");
    */
    if (red > blue and red > green)
        return Red;
    else if (green > red and green > blue)
        return Green;
    else if (blue > red and blue > green)
        return Blue;
    else
        return None;
}