#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

class Motor {
   private:
    uint8_t encoderPin;
    uint8_t pin1, pin2;

    unsigned long int goal;
    volatile unsigned long int cont;

    uint8_t whichISR;
    static Motor *instance0;
    static Motor *instance1;
    static Motor *instance2;
    static Motor *instance3;

    static void isr0();
    static void isr1();
    static void isr2();
    static void isr3();

    void handleInterrupt();

   public:
    Motor(const byte _whichISR);
    ~Motor();

    void setPins(uint8_t _encoderPin, uint8_t _pin1, uint8_t _pin2);
    void begin();

    void forward(unsigned long int _goal);
    void forward(uint8_t vel);
    void forward();

    void backward(unsigned long int _goal);
    void backward(uint8_t vel);
    void backward();

    void stop();
};

#endif  // MOTOR_H