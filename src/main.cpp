#include "Robot.hpp"

Robot boberto;

void setup() {

    Serial.begin(115200);

    boberto.begin();

    Serial.println(":: Oi, eu sou o Boberto ::");

    boberto.goToContainerZone();
    boberto.checkColor();
    boberto.catchContainer();
    boberto.goToCurrentDestination();
    while (true) {
        boberto.thereAndBackAgain();
        boberto.followLineUntilContainer(); 
        boberto.checkColor();
        boberto.catchContainer();
        boberto.goToCurrentDestination();
    
    }
}

void loop() {}