#include "Robot.hpp"

Robot::Robot() {
    // Inicia os pinos dos motores
    frontRight.setPins(19, 44, 46);
    frontLeft.setPins(18, 4, 45);
    backRight.setPins(3, 7, 8);
    backLeft.setPins(2, 6, 5);

    frontLeft.begin();
    frontRight.begin();
    backLeft.begin();
    backRight.begin();

    sensorFL.setPin(23);
    sensorFR.setPin(29);
    sensorBL.setPin(27);
    sensorBR.setPin(25);

    // sensorSB.setPin(35);
    // sensorSF.setPin(34);

    // sensorFLL.setPin(31);
    sensorFRR.setPin(31);

    blueSensorF.setPin(51);
    blueSensorB.setPin(49);

    containerSensor.setPin(47);
}

Robot::~Robot() {}

void Robot::begin() {
    // Calibra o sensor de cor
    // colorSensor.ledOn();
    // Serial.println("Going to init");
    // colorSensor.init();
    // Serial.println("Initialized");
    // Serial.println("Going to calibrate");
    // colorSensor.calibrate();
    // Serial.println("Calibrated");

    // Seta a posição inicial da garra
    // claw.goHome();
    // claw.goToContainer(1.05);

    // Serial.println("Calibrating...");
    // delay(500);
    // colorSensor.calibrate();
    // Serial.println("Calibrated");
    // delay(500);

    // claw.retract();
    claw.goHome();
    claw.goToContainer(5.5);
}

void Robot::stop() {
    frontLeft.stop();
    frontRight.stop();
    backLeft.stop();
    backRight.stop();
}

void Robot::forward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.forward(100, vel);
            backLeft.forward(100, vel);
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::backward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.backward(100, vel);
            backLeft.backward(100, vel);
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::sidewaysRight(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.backward(100, vel);
            backLeft.backward(100, vel);
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::sidewaysLeft(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.forward(100, vel);
            backLeft.forward(100, vel);
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::rotateLeft(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.forward(0, vel);
        backLeft.backward(0, vel);
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.forward(100, vel);
            backLeft.backward(100, vel);
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::rotateRight(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.backward(0, vel);
        backLeft.forward(0, vel);
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.backward(100, vel);
            backLeft.forward(100, vel);
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveRightForward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.stop();
            backLeft.stop();
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveRightBackward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.stop();
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.stop();
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.stop();
            frontRight.backward(100, vel);
            backLeft.backward(100, vel);
            backRight.stop();

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveLeftForward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.stop();
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.stop();
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.stop();
            frontRight.forward(100, vel);
            backLeft.forward(100, vel);
            backRight.stop();

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveLeftBackward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.stop();
            backLeft.stop();
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::smoothRotateLeft() {
    frontRight.backward(0, 255);
    backRight.backward(0, 255);

    backLeft.backward(0, 18);
    frontLeft.backward(0, 18);
}

void Robot::smoothRotateRight() {
    frontRight.backward(0, 18);
    backRight.backward(0, 18);

    backLeft.backward(0, 255);
    frontLeft.backward(0, 255);
}

/*void Robot::catchContainer(uint8_t container) {
    claw.extend();
    claw.goToContainer(container);
    claw.goToContainer(container + 0.5);
    claw.ajustContainer();
    claw.goToContainer(5.5);
}*/

void Robot::catchContainer() {
    uint8_t containerHeight = arena.containers[currentZone].getHeight(clawSide);

    claw.goToContainer(containerHeight + 0.5);

    currentDestination = colorSensor.readColor();

    claw.goToContainer(containerHeight + 0.2);
    claw.extend();
    claw.goToContainer(containerHeight);
    claw.goToContainer(5.5);

    arena.containers[currentZone].updateHeight(clawSide);

    if (arena.containers[currentZone].isEmpty(clawSide)) {
       currentZone++;
       if (currentZone == 3)
           currentZone = 0;
    }
}

void Robot::releaseContainer(COLOR color) {
    claw.ajustContainer();

    switch (color) {
        case Green:
            claw.goToContainer(arena.greenShip.currentHeight);
            arena.greenShip.increment();
            break;

        case Blue:
            claw.goToContainer(arena.blueShip.currentHeight);
            arena.blueShip.increment();
            break;

        case Red:
            stop();
            break;

        default:
            stop();
            break;
    }

    claw.retract();
    claw.goToContainer(5.5);
}

void Robot::findBlackLine() {
    forward();

    // while (!sensorFL.getValue() and !sensorFR.getValue()) delay(1);
    // while (sensorFL.getValue() or sensorFR.getValue()) delay(1);
    
    while (!sensorFL.getValue() or !sensorFR.getValue()) delay(1);
    while (sensorFL.getValue() and sensorFR.getValue()) delay(1);
    
    stop();

    forward(2, 200);
}

void Robot::findBlueLine() {
    sidewaysLeft();
    while (blueSensorF.getValue() && blueSensorB.getValue()) {
        delay(1);
    }

    stop();
}

void Robot::alignBetweenContainers() {
    switch (currentZone) {
        case 0:
            while (!sensorFR.getValue()) sidewaysRight();
            
            sidewaysRight(1, 255);
            forward(1, 255);

            while (sensorFR.getValue()) sidewaysRight();

            sidewaysRight(1, 255);
            
            while (!sensorFR.getValue()) sidewaysRight();

            while (sensorFR.getValue()) sidewaysRight();

            stop();

            break;
        case 1:

            while (!sensorFR.getValue()) sidewaysRight();

            while (sensorFR.getValue()) sidewaysRight();

            stop();

            break;
        case 2:
            
            while (!sensorFL.getValue()) sidewaysLeft();

            while (sensorFL.getValue()) sidewaysLeft();

            stop();

            break;
        default:
            stop();
            break;
    }
}

void Robot::alignWithShip() {
    while (!blueSensorF.getValue() or !blueSensorB.getValue()) {
        if (blueSensorB.getValue())
            rotateLeft(0, 150);
        else if (blueSensorF.getValue())
            rotateRight(0, 150);
        else if (!blueSensorF.getValue() and !blueSensorB.getValue())
            sidewaysLeft(0, 150);
    }

    Ship destination;
    if(currentDestination == Green)
        destination = arena.greenShip;
    else if(currentDestination == Blue)
        destination = arena.blueShip;
    
    if(destination.currentHeight != 1) {
        if (containerSensor.getValue()) {
            while (containerSensor.getValue()) backward(0, 180);

            delay(100);

            while (!containerSensor.getValue()) forward(0, 180);
            
        } else 
            while (!containerSensor.getValue()) forward(0, 180);   
    }
    
    stop();
}

void Robot::alignWithContainersPile() {
    // Verifica se a primeira pilha está vazia
    if (arena.containers[currentZone].clawSide[0]) {
        do {
            if (sensorFL.getValue())
                rotateLeft();
            else if (sensorFR.getValue())
                rotateRight();
            else
                forward(0, 200);
        } while (!sensorBL.getValue());

        do {
            if (sensorFL.getValue())
                rotateLeft();
            else if (sensorFR.getValue())
                rotateRight();
            else
                forward(0, 200);
        } while (sensorBL.getValue());

        forward(7, 200);

        // alinhando com a linha para pegar o container retinho sem ser tortao
        Serial.println("Fazendo os role de alinhar!");
        sidewaysLeft(1,200);
        while (!sensorBL.getValue() && !sensorFL.getValue()) {
            if (!sensorBL.getValue() && sensorFL.getValue()) {
                rotateLeft(0, 200);
            } else if (sensorBL.getValue() && !sensorFL.getValue()) {
                rotateRight(0, 200);
            } else {
                sidewaysRight(0, 200);
            }
        }

        stop();
        
    } else {
        while (!sensorFL.getValue()) {
            if (sensorFL.getValue())
                rotateLeft();
            else if (sensorFR.getValue())
                rotateRight();
            else
                forward(0, 200);
        }

        backward(7, 150); 
    }
}

void Robot::followLineUntilContainer() {
    while (!containerSensor.getValue()) {
        if (sensorFL.getValue())
            rotateLeft(0, 180);
        else if (sensorFR.getValue())
            rotateRight(0, 180);
        else
            forward(0, 180);
    }
    
    stop();
}

void Robot::followLineUntilGap() {
    // Anda até encontrar o primeiro container
    uint16_t dist = 130;
    while (dist > 120) {

        delay(30);
        Serial.print("Vou ler o lidar: ");
        dist = lidar.getDistance();
        Serial.println(dist);

        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward(0, 180);
    }
    
    // Anda até sair do container
    /*dist = 0;
    lidar.begin();
    while (dist < 120) {

        delay(20);
        dist = lidar.getDistance();
        Serial.println(dist);

        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward(0, 150);
    }*/

    stop();
}

void Robot::followHorizontalRight() {
    while (!sensorFRR.getValue()) {
        if (sensorBR.getValue() and sensorBL.getValue())
            backward();
        else if (sensorBR.getValue())
            smoothRotateRight();
        else if (sensorBL.getValue())
            smoothRotateLeft();
        else 
            backward();
    }

    delay(100);

    while (sensorFRR.getValue()) {
        if (sensorBR.getValue() and sensorBL.getValue())
            backward();
        else if (sensorBR.getValue())
            smoothRotateLeft();
        else if (sensorBL.getValue())
            smoothRotateRight();
        else 
            backward();
    }

    delay(100);

    stop();

    /*
    while (!sensorFRR.getValue()) {
        if (sensorFL.getValue() and sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() and sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() and sensorBL.getValue())
            moveLeftBackward();
        else if (sensorFR.getValue() and sensorBR.getValue())
            moveRightBackward();
        else
            backward();
    }

    while (sensorFRR.getValue()) {
        if (sensorFL.getValue() and sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() and sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() and sensorBL.getValue())
            moveLeftBackward();
        else if (sensorFR.getValue() and sensorBR.getValue())
            moveRightBackward();
        else
            backward();
    }

    backward(1, 200);
    */
}

void Robot::followHorizontalLeft() {
    while (!sensorFRR.getValue()) {
        if (sensorFL.getValue() and sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() and sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() and sensorBL.getValue())
            moveLeftForward();
        else if (sensorFR.getValue() and sensorBR.getValue())
            moveRightForward();
        else
            forward();
    }

    if (currentZone != 0) {
        while (sensorFRR.getValue()) {
            if (sensorFL.getValue() and sensorBR.getValue())
                rotateLeft();
            else if (sensorFR.getValue() and sensorBL.getValue())
                rotateRight();
            else if (sensorFL.getValue() and sensorBL.getValue())
                moveLeftForward();
            else if (sensorFR.getValue() and sensorBR.getValue())
                moveRightForward();
            else
                forward();
        }
    }

    /*
    while (!sensorFRR.getValue()) {
        if (sensorFL.getValue() and sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() and sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() and sensorBL.getValue())
            moveLeftForward();
        else if (sensorFR.getValue() and sensorBR.getValue())
            moveRightForward();
        else
            forward();
    }
    */

    forward(1, 200);
    stop();
}

void Robot::goToContainerZone() {
    findBlackLine();
    alignBetweenContainers();
    followLineUntilContainer();
}

void Robot::goToBlueShip() {
    if (arena.side) {
        if (arena.blueShip.currentPile == 0) {
            if (currentZone == 0) {
                forward(2, 200);
                rotateLeft(16);

                while (!sensorFR.getValue()) {
                    if(sensorFR.getValue() and !sensorBR.getValue())
                        rotateLeft(0, 200);
                    else if (sensorBR.getValue() and !sensorFR.getValue())
                        rotateRight(0, 200);
                    else 
                        sidewaysRight(0, 200);
                }

                sidewaysRight(1, 200);

                followHorizontalLeft();

                backward(7, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 200);

                while (sensorFRR.getValue()) sidewaysLeft(0, 200);

                alignWithShip();

            } else if (currentZone == 1) {
                rotateLeft(16);

                while (!sensorFL.getValue() or !sensorBL.getValue()) {
                    if(sensorFL.getValue() and sensorBL.getValue())
                        rotateLeft(0, 180);
                    else if (sensorBL.getValue() and !sensorFL.getValue())
                        rotateRight(0, 180);
                    else 
                        sidewaysRight(0, 180);
                }

                // while (!sensorBR.getValue()) {
                //     if(sensorFR.getValue() and !sensorBR.getValue())
                //         rotateLeft(0, 200);
                //     else if (sensorBR.getValue() and !sensorFR.getValue())
                //         rotateRight(0, 200);
                //     else 
                //         sidewaysRight(0, 200);
                // }
                // sidewaysRight(1, 200);


                followHorizontalRight();

                backward(5, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 200);

                while (sensorFRR.getValue()) sidewaysLeft(0, 200);

                sidewaysLeft(3, 200);

                alignWithShip();

            } else if (currentZone == 2) {
                rotateLeft(16);

                while (!sensorFR.getValue() or !sensorBR.getValue()) {
                    if(sensorFR.getValue() and !sensorBR.getValue())
                        rotateLeft(0, 180);
                    else if (sensorBR.getValue() and !sensorFR.getValue())
                        rotateRight(0, 180);
                    else 
                        sidewaysRight(0, 180);
                }

                sidewaysRight(1, 180);

                followHorizontalRight();    

                // sidewaysRight
                frontLeft.forward(50, 180);
                frontRight.backward(50, 180);
                backLeft.backward(50, 180);
                backRight.forward(50, 180);

                followHorizontalRight();

                backward(3, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

                sidewaysLeft(3, 180);

                alignWithShip();
            }
        } else {
            // Código para ir para a segunda pilha 
        }
    } else {
        rotateLeft(35);
        followHorizontalLeft();
        findBlueLine();
        alignWithShip();
    }
}

void Robot::goToGreenShip() {
    /*
        side: true ==> green | blue
              false ==> blue | green
    */
    if (arena.side) {
        if (arena.greenShip.currentPile == 0) {
            if (currentZone == 0) {
                rotateLeft(16);

                while (!sensorFR.getValue()) {
                    if(sensorFR.getValue() and !sensorBR.getValue())
                        rotateLeft(0, 180);
                    else if (sensorBR.getValue() and !sensorFR.getValue())
                        rotateRight(0, 180);
                    else 
                        sidewaysRight(0, 180);
                }

                sidewaysRight(1, 180);

                // Serial.println("followHorizontalLeft 1");
                followHorizontalLeft();
                // Serial.println("followHorizontalLeft 2");          
                followHorizontalLeft();
                followHorizontalLeft();

                backward(6, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

                alignWithShip();
                
            } else if (currentZone == 1) {
                rotateLeft(16);

                while (!sensorFR.getValue() or !sensorBR.getValue()) {
                    if(sensorFR.getValue() and !sensorBR.getValue())
                        rotateLeft(0, 180);
                    else if (sensorBR.getValue() and !sensorFR.getValue())
                        rotateRight(0, 180);
                    else 
                        sidewaysRight(0, 180);
                }

                sidewaysRight(1, 180);

                // Serial.println("followHorizontalLeft 1");
                followHorizontalLeft();
                // Serial.println("followHorizontalLeft 2");          
                followHorizontalLeft();

                backward(6, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

                alignWithShip();

            } else if (currentZone == 2) {
                Serial.println("Currente Zone 2");
                rotateLeft(16);

                while (!sensorFR.getValue() or !sensorBR.getValue()) {
                    if(sensorFR.getValue() and !sensorBR.getValue())
                        rotateLeft(0, 180);
                    else if (sensorBR.getValue() and !sensorFR.getValue())
                        rotateRight(0, 180);
                    else 
                        sidewaysRight(0, 180);
                }

                sidewaysRight(1, 180);

                followHorizontalLeft();

                backward(6, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

                alignWithShip();
            }
        } else {
            // Código para ir para a segunda pilha 
        }
    } else {
        rotateLeft(35);
        followHorizontalRight();
        findBlueLine();
        alignWithShip();
    }
}

void Robot::goToCurrentDestination() {
    switch (currentDestination) {
        case Green:
            backwardUntilBlackLine();
            goToGreenShip();
            releaseContainer(Green);
            break;

        case Blue:
            backwardUntilBlackLine();
            goToBlueShip();
            releaseContainer(Blue);
            break;

        case Red:
            /* code */
            stop();
            break;

        default:
            stop();
            break;
    }
}

void Robot::thereAndBackAgain() {
    if (currentDestination == Blue) {
        while (!sensorFRR.getValue()) sidewaysRight();

        while (sensorFRR.getValue()) sidewaysRight();

        rotateRight(15);
        forward(2, 200);

        while (!sensorFL.getValue()) sidewaysLeft();

        while (sensorFL.getValue()) sidewaysLeft();

        forward(3, 150);

        currentZone = 1;

    } else if (currentDestination == Green) {
        while (!sensorFRR.getValue()) sidewaysRight();

        while (sensorFRR.getValue()) sidewaysRight();

        rotateRight(15);
        forward(2, 200);

        while (!sensorFR.getValue()) sidewaysRight();

        while (sensorFR.getValue()) sidewaysRight();

        forward(3, 150);

        currentZone = 2;
    }
}

void Robot::backwardUntilBlackLine() {
    if (currentZone) {
        while (!sensorFL.getValue() or !sensorFR.getValue()) backward();

        stop();
    } else {

        while (!blueSensorF.getValue()) backward();

        stop();
    }
}

void Robot::testMoviments() {
    forward(2);
    delay(10);
    backward(2);
    delay(10);
    //sidewaysRight(40);
    //delay(1000);
    //sidewaysLeft(40);
    //delay(1000);
    
    // rotateLeft(20);
    // delay(1000);
    // rotateRight(20);
    // delay(1000);
}

void Robot::testClaw() {
    claw.extend();

    delay(2000);

    claw.ajustContainer();

    delay(2000);

    claw.retract();

    delay(2000);
    // catchContainer(1);
    // delay(1000);
    // releaseContainer(Green);
    // delay(1000);
    // claw.extend();
    // delay(2000);
    // claw.ajustContainer();
    // delay(1000);
    // claw.retract();
}

void Robot::testColorSensor() {
    COLOR color = colorSensor.readColor();

    Serial.print("Color: ");
    switch (color) {
        case Red:
            Serial.println("Red\n");
            break;

        case Green:
            Serial.println("Green\n");
            break;

        case Blue:
            Serial.println("Blue\n");
            break;

        default:
            Serial.println("404 Color Not Found\n");
            break;
    }

}

void Robot::testDistanceSensor() {
    uint16_t start = millis();
    uint16_t measurement = lidar.getDistance();
    uint16_t end = millis();

    Serial.print("Distance: ");
    Serial.print(measurement);
    Serial.print(" ");
    Serial.print(end - start);
    Serial.print("ms\n");
}