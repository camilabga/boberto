#ifndef COLORSENSOR_HPP
#define COLORSENSOR_HPP

#include <Arduino.h>
#include <Wire.h>

// ADJD-S311's I2C address, don't change
#define ADJD_S311_ADDRESS 0x74

#define RED 0
#define GREEN 1
#define BLUE 2
#define CLEAR 3

// ADJD-S311's register list
#define CTRL 0x00
#define CONFIG 0x01
#define CAP_RED 0x06
#define CAP_GREEN 0x07
#define CAP_BLUE 0x08
#define CAP_CLEAR 0x09
#define INT_RED_LO 0xA
#define INT_RED_HI 0xB
#define INT_GREEN_LO 0xC
#define INT_GREEN_HI 0xD
#define INT_BLUE_LO 0xE
#define INT_BLUE_HI 0xF
#define INT_CLEAR_LO 0x10
#define INT_CLEAR_HI 0x11
#define DATA_RED_LO 0x40
#define DATA_RED_HI 0x41
#define DATA_GREEN_LO 0x42
#define DATA_GREEN_HI 0x43
#define DATA_BLUE_LO 0x44
#define DATA_BLUE_HI 0x45
#define DATA_CLEAR_LO 0x46
#define DATA_CLEAR_HI 0x47
#define OFFSET_RED 0x48
#define OFFSET_GREEN 0x49
#define OFFSET_BLUE 0x4A
#define OFFSET_CLEAR 0x4B

struct RGBC {
    int red;
    int blue;
    int green;
    int clear;
};

class ColorSensor {
    private:
        uint8_t ledPin;

        // Valores iniciais para os registradores
        unsigned char colorCap[4];
        unsigned int colorInt[4];
        signed char colorOffset[4];

        // Operação com os registradores
        /* 
            Performs the offset reading and stores the offset data 
            into the colorOffset[] array.
        */
        void getOffset();
        // Writes a byte of data to a specific sensor address
        void writeRegister(unsigned char data, unsigned char address);
        // Reads a byte of data from sensor address
        unsigned char readRegister(unsigned char address);
        // Writes two bytes of data to sensor address and address + 1
        int readRegisterInt(unsigned char address);
        
        // Calibrações 
        // Calibrates the C int registers
        int calibrateClear();
        // Calibrates R, G, and B int registers
        int calibrateColor();
        // Calibrates the RGB, and C cap registers
        void calibrateCapacitors();
        // Writes a 12-bit value to the LO and HI integration registers
        void writeInt(int address, int gain);
        
        // Leiuras
        /*
            Commands the sensor to perform a measurement, 
            and store the data into the data registers.
        */
        void performMeasurement();
        // Read data registers and return a RGBC measurement
        RGBC read();

    public:
        ColorSensor(uint8_t _ledPin);
        
        void init();

        void calibrate();
        void ledOn();
        void ledOff();

        /*
            Realiza a leitura da cor. Flags:
            0: Red
            1: Green
            2: Blue
        */
        uint8_t readColor();
};

#endif // COLORSENSOR_HPP