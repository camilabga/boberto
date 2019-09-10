#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

class Motor {
    private:
        // Pinos do motor
        uint8_t encoderPin;
        uint8_t pin1, pin2;

        // Variáveis para acompanhar o encoder
        unsigned long int goal;
        volatile unsigned long int cont;

        /*
            Singletons para que as instancias da classe 
            saibam que função de interrrupt usar.
            Se forem necessárias mais intâncias adicionar 
            mais singletons.
        */ 
        uint8_t whichISR;
        static Motor *instance0;
        static Motor *instance1;
        static Motor *instance2;
        static Motor *instance3;

        // Wrapper para a função de interrupt
        static void isr0();
        static void isr1();
        static void isr2();
        static void isr3();

        // Função de interrupt
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

#endif  // MOTOR_HPP