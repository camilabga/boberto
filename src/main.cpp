#include "Robot.hpp"
#define CALL_INTERVAL 4000

Robot boberto;
unsigned long int lastCall = 0;

void setup() {
    Serial.begin(9600);
    
    Serial.println(":: Ready ::");
}

void loop() {
    if(millis() - lastCall >= CALL_INTERVAL) {
        
        boberto.forward(3000);
    
        lastCall = millis();
    }
}
