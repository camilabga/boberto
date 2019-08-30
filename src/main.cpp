#include "Robot.hpp"
#include "Claw.hpp"
#define CALL_INTERVAL 4000

Robot boberto;
Claw claw(26, 27, 28, 29);
unsigned long int lastCall = 0;

void setup() {
    Serial.begin(9600);

    Serial.println(":: Ready ::");
}

void loop() {
    claw.goUp();
    delay(1000);
    claw.goHome();
    delay(1000);
}
