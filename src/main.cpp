#include "Robot.hpp"
#define CALL_INTERVAL 2000

Robot boberto;
unsigned long int lastCall = 0;

void setup() {
    Serial.begin(9600);

    boberto.frontLeft.setupInterruptHandler(
        []() { boberto.frontLeft.handleInterrupt(); }, 
        CHANGE
    );
    boberto.frontRight.setupInterruptHandler(
        []() { boberto.frontRight.handleInterrupt(); }, 
        CHANGE
    );
    boberto.backLeft.setupInterruptHandler(
        []() { boberto.backLeft.handleInterrupt(); }, 
        CHANGE
    );
    boberto.backRight.setupInterruptHandler(
        []() { boberto.backRight.handleInterrupt(); }, 
        CHANGE
    );
}

void loop() {
    if(millis() - lastCall >= CALL_INTERVAL) {
        
        boberto.forward(1000);
    
        lastCall = millis();
    } 
}
