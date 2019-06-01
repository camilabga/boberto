#include "Robot.hpp"
#define CALL_INTERVAL 5000

Robot boberto;
unsigned long int lastCall = 0;

void motor1Int(void) {
    boberto.frontLeft.handleInterrupt();
}

void motor2Int(void) {
    boberto.frontRight.handleInterrupt();
}

void motor3Int(void) {
    boberto.backLeft.handleInterrupt();
}

void motor4Int(void) {
    boberto.backRight.handleInterrupt();
}

void setup() {
    Serial.begin(9600);

    boberto.frontLeft.setupInterruptHandler(motor1Int, CHANGE);
    boberto.frontRight.setupInterruptHandler(motor2Int, CHANGE);
    boberto.backLeft.setupInterruptHandler(motor3Int, CHANGE);
    boberto.backRight.setupInterruptHandler(motor4Int, CHANGE);

    boberto.forward(3000);
}

void loop() {
    if(millis() - lastCall >= CALL_INTERVAL) {
        Serial.println("Move");
        
        boberto.forward(3000);
        
        lastCall = millis();
    }
}
