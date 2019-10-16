// #include <Wire.h>
#include "Robot.hpp"
#define BOTAO_CONFIG 31

Robot boberto;

void setup() {
    // pinMode(BOTAO_CONFIG, INPUT);

    // Wire.begin();
    Serial.begin(115200);
    
    boberto.begin();

    // esperar botao para calibrar o sensor de cor
    // while (!digitalRead(BOTAO_CONFIG)) if(digitalRead(BOTAO_CONFIG)) break;
    // boberto.calibrateColorSensor();

    Serial.println(":: Ready ::");

    // wait botao para começar rotina padrão do robô
    // while (!digitalRead(BOTAO_CONFIG)) if(digitalRead(BOTAO_CONFIG)) break;
    
    boberto.goToContainerZone();
    boberto.catchContainer();
    boberto.goToCurrentDestination();

    while (true) {
        boberto.thereAndBackAgain();
        boberto.alignWithContainersPile();  
        boberto.catchContainer();
        boberto.goToCurrentDestination();
    }
    
}

void loop() {
    // boberto.goToContainerZone();

    // boberto.catchContainer();

    // boberto.chooseContainerDestination();

    // boberto.goToCurrentDestination();

    /*boberto.followLineUntilGap();

    boberto.catchContainer(1);

    boberto.backwardUntilBlackLine();

    boberto.goToGreenShip(2);*/

    // delay(666666);

    //boberto.testMoviments();
    
    //boberto.testClaw();

    // boberto.testDistanceSensor();
    // boberto.testColorSensor();
    // delay(300);
}