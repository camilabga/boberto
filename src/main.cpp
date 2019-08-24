#include "Robot.hpp"
#define CALL_INTERVAL 4000

Robot boberto;
unsigned long int lastCall = 0;

void setup() {
    Serial.begin(9600);

    Serial.println(":: Ready ::");
}

void loop() {
    boberto.findBlackLine();
    boberto.alignBetweenContainers();
}
