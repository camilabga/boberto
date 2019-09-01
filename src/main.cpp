#include <Wire.h>
#include "Claw.hpp"
#include "DistanceSensor.hpp"
#include "Robot.hpp"
#define CALL_INTERVAL 4000

Robot boberto;
unsigned long int lastCall = 0;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    boberto.begin();

    Serial.println(":: Ready ::");

    boberto.catchContainer(1);

}

void loop() {
    /*
    boberto.findBlackLine();
    boberto.alignBetweenContainers();
    boberto.followLineUntilGap();

    boberto.catchContainer(4);

    boberto.backward();
    delay(5000);
    boberto.stop();
    boberto.sidewaysLeft();
    delay(2000);
    boberto.stop();

    boberto.releaseContainer(1);

    delay(666666);
    */
}