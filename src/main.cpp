#include <Wire.h>
#include "Claw.hpp"
#include "ColorSensor.hpp"
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

}

void loop() {
    boberto.rotateLeft(10);
    delay(2000);
    boberto.rotateRight(10);
    delay(2000);

    boberto.findBlackLine();
    boberto.alignBetweenContainers();
    boberto.followLineUntilGap();

    boberto.catchContainer(2);

    boberto.backwardUntilBlackLine();

    boberto.goToGreenShip(1);

    boberto.followLineUntilGap();

    boberto.catchContainer(1);

    boberto.backwardUntilBlackLine();

    boberto.goToGreenShip(2);

    delay(666666);
}