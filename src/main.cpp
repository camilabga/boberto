#include <Wire.h>
#include "Robot.hpp"
#include "Claw.hpp"
#include "DistanceSensor.hpp"
#define CALL_INTERVAL 4000

Robot boberto;
Claw claw(26, 27, 28, 29);
DistanceSensor lidar;

unsigned long int lastCall = 0;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    lidar.begin();

    Serial.println(":: Ready ::");
}

void loop() {
    Serial.print("Container gap? ");
    Serial.print(lidar.getContainerGap());
    Serial.print("  ");
    Serial.println(lidar.getDistance());

    delay(1000);
}