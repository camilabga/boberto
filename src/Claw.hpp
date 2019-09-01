#ifndef CLAW_H
#define CLAW_H

#include <Arduino.h>

class Claw {
    private:
        // Pinos do motor de passo
        uint8_t setPin; 
        uint8_t dirPin;
        
        // Pinos do motor DC
        uint8_t motorPin1;
        uint8_t motorPin2;

        // Pino do fim de curso
        uint8_t endStopPin;

        // Altura atual da garra
        float height;

    public:
        Claw(uint8_t _setPin, uint8_t _dirPin, uint8_t _motorPin1, uint8_t _motorPin2, uint8_t _endStopPin);
        ~Claw();

        void goUp();
        void goDown();

        void goHome();

        void goToContainer(float container);
        void catchContainer(uint8_t container);

        void extend();
        void retract();
        void ajustContainer();
        void stop();
    
};

#endif // CLAW_H