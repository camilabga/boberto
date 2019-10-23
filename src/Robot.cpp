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

    containerSensorF.setPin(41);
    containerSensorB.setPin(47);

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
    frontRight.backward(0, 200);
    backRight.backward(0, 200);

    backLeft.backward(0, 70);
    frontLeft.backward(0, 70);
}

void Robot::smoothRotateRight() {
    frontRight.backward(0, 70);
    backRight.backward(0, 70);

    backLeft.backward(0, 200);
    frontLeft.backward(0, 200);
}

void Robot::catchContainer() {
    Serial.println("\ncatchContainer");
    uint8_t containerHeight = arena.containers[currentZone].getHeight(clawSide);

    // claw.goToContainer(containerHeight + 0.5);
    // currentDestination = colorSensor.readColor();

    Serial.print("Estou na zona: ");
    Serial.print(currentZone);
    Serial.print(" e vou pegar o container na altura: ");
    Serial.println(containerHeight);

    claw.goToContainer(containerHeight + 0.2);
    claw.extend();
    claw.goToContainer(containerHeight);
    claw.goToContainer(5.5);

    // Serial.print("Pilha 0: ");
    // Serial.println(arena.containers[currentZone].locked[0]);

    // Serial.println("Vou atualizar a altura");
    arena.containers[currentZone].updateHeight(clawSide);
    
    // Serial.print("Altura atualizada: ");
    // Serial.println(arena.containers[currentZone].getHeight(clawSide));

    Serial.println("\n");
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
            claw.goToContainer(5.5);
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
            rotateLeft(0, 180);
        else if (blueSensorF.getValue())
            rotateRight(0, 180);
        else if (!blueSensorF.getValue() and !blueSensorB.getValue())
            sidewaysLeft(0, 180);
    }

    sidewaysRight(2, 180);


    while (!blueSensorF.getValue() or !blueSensorB.getValue()) {
        if (blueSensorB.getValue())
            rotateLeft(0, 200);
        else if (blueSensorF.getValue())
            rotateRight(0, 200);
        else if (!blueSensorF.getValue() and !blueSensorB.getValue())
            sidewaysLeft(0, 100);
    }


    Ship destination;
    if(currentDestination == Green)
        destination = arena.greenShip;
    else if(currentDestination == Blue)
        destination = arena.blueShip;
    
    Serial.print("currentHeight: ");
    Serial.println(destination.currentHeight);

    if(destination.currentHeight > 1) {
        if (containerSensorB.getValue()) {
            while (containerSensorB.getValue()) backward(0, 150);

            delay(100);

            while (!containerSensorB.getValue()) forward(0, 150);
            
        } else 
            while (!containerSensorB.getValue()) forward(0, 150);   
        
        
        Serial.println("Vou dar o backward");
        stop();
        frontLeft.backward(25, 150);
        frontRight.backward(25, 150);
        backLeft.backward(25, 150);
        backRight.backward(25, 150);
        delay(100);

    } else {
       

        if (currentDestination == Blue) {
            
            stop();
            delay(1000);
            frontLeft.backward(30, 100);
            frontRight.forward(30, 100);
            backLeft.forward(30, 100);
            backRight.backward(30, 100);
            delay(1000);
            stop();

            while (blueSensorB.getValue()) backward(0, 100);

            forward(1, 150);
        } else {
            while (blueSensorF.getValue()) forward(0, 100);

            backward(2, 150);
        }   
    }

    stop();
}

void Robot::alignWithShipSide() {
    while (!blueSensorF.getValue() or !blueSensorB.getValue()) {
        if (blueSensorB.getValue())
            rotateLeft(0, 180);
        else if (blueSensorF.getValue())
            rotateRight(0, 180);
        else if (!blueSensorF.getValue() and !blueSensorB.getValue())
            sidewaysLeft(0, 180);
    }

    Ship destination;
    if(currentDestination == Green)
        destination = arena.greenShip;
    else if(currentDestination == Blue)
        destination = arena.blueShip;
    
    if(destination.currentHeight != 1) {
        if (containerSensorB.getValue()) {
            while (containerSensorB.getValue()) backward(0, 180);

            delay(100);

            while (!containerSensorB.getValue()) forward(0, 180);
            
        } else 
            while (!containerSensorB.getValue()) forward(0, 180);   
    } 

    // Backward
    frontLeft.backward(100, 200);
    frontRight.backward(100, 200);
    backLeft.backward(100, 200);
    backRight.backward(100, 200);

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
    Serial.println("followLineUntilContainer");

    // Se a pilha estiver travada ou a primeira pilha estiver vazia
    if (arena.containers[currentZone].isLocked()) {
        Serial.println("Vou para a segunda pilha e a primeria esta travada");

        forward(1, 150);

        Serial.println("Vou detectar o container");
        while (!containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }
        
        stop();
        
        // Serial.println("Vou sair do container");
        // while (containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        // }

        stop();
        
    } else if (!arena.containers[currentZone].clawSide[0]) {
        Serial.println("Vou para a segunda pilha e segunda esta vazia");

        while (!containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }
        
        Serial.println("Sai do container");

        while (containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }

        while (!containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }

        Serial.println("Sai do container");
    } else {
        while (!containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }
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
        if (sensorFR.getValue() and sensorFL.getValue())
            forward();
        else if (sensorFR.getValue())
            smoothRotateLeft();
        else if (sensorFL.getValue())
            smoothRotateRight();
        else 
            forward();
    }

    if (currentZone != 0) {
        while (sensorFRR.getValue()) {
            if (sensorFR.getValue() and sensorFL.getValue())
                forward();
            else if (sensorFR.getValue())
                smoothRotateLeft();
            else if (sensorFL.getValue())
                smoothRotateRight();
            else
                forward(); 
        }
    }

    /*
    // Estratégia do x
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
            // Primeira pilha
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

                backward(4, 200);

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

                backward(3, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

                sidewaysLeft(3, 180);

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
            // Segunda pilha 
            if (currentZone == 0) {
                forward(3, 200);

                while (!sensorFRR.getValue()) sidewaysLeft();
                while (sensorFRR.getValue()) sidewaysLeft();

                delay(100);

                while (!sensorFRR.getValue()) sidewaysLeft();
                while (sensorFRR.getValue()) sidewaysLeft();

                sidewaysLeft(5, 255);
                backward(8, 200);

                while (!blueSensorF.getValue()) backward();
                while (blueSensorF.getValue()) backward();

                backward(13, 255);

                rotateLeft(32, 255);

                alignWithShipSide();

            } else if (currentZone == 1) {
                sidewaysLeft(12, 255);
                backward(8, 200);

                while (!blueSensorF.getValue()) backward();
                while (blueSensorF.getValue()) backward();

                backward(13, 255);

                rotateLeft(32, 255);

                alignWithShipSide();

            } else if (currentZone == 2) {
                sidewaysRight(12, 255);
                backward(8, 200);

                while (!blueSensorF.getValue()) backward();
                while (blueSensorF.getValue()) backward();

                backward(13, 255);

                rotateLeft(32, 255);

                alignWithShipSide();
            }
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
        // Primeira pilha
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

                followHorizontalLeft();         
                followHorizontalLeft();
                followHorizontalLeft();

                stop();
                delay(100);
                backward(7, 200);

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

                followHorizontalLeft();      
                forward(3, 200);    
                followHorizontalLeft();

                stop();
                delay(100);
                backward(7, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

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

                followHorizontalLeft();

                stop();
                delay(100);
                backward(7, 200);

                while (!sensorFRR.getValue()) sidewaysLeft(0, 180);

                while (sensorFRR.getValue()) sidewaysLeft(0, 180);

                alignWithShip();
            }
        } else {
            // Segunda pilha 
            if (currentZone == 0) {
                forward(3, 200);

                while (!sensorFRR.getValue()) sidewaysLeft();
                while (sensorFRR.getValue()) sidewaysLeft();

                delay(100);

                while (!sensorFRR.getValue()) sidewaysLeft();
                while (sensorFRR.getValue()) sidewaysLeft();

                sidewaysLeft(5, 255);
                backward(8, 200);

                while (!blueSensorF.getValue()) backward();

                while (blueSensorF.getValue()) backward();

                backward(13, 255);

                alignWithShipSide();

            } else if (currentZone == 1) {
                sidewaysLeft(12, 255);
                backward(8, 200);

                while (!blueSensorF.getValue()) backward();
                while (blueSensorF.getValue()) backward();

                backward(13, 255);

                alignWithShipSide();

            } else if (currentZone == 2) {
                sidewaysRight(12, 255);
                backward(8, 200);

                while (!blueSensorF.getValue()) backward();
                while (blueSensorF.getValue()) backward();

                backward(13, 255);

                alignWithShipSide();

            }
        }
    } else {
        rotateLeft(35);
        followHorizontalRight();
        findBlueLine();
        alignWithShip();
    }
}

void Robot::goToNextPile() {
    
    Serial.println("\ngoToNextPile");

    Serial.print("currentZone: ");
    Serial.println(currentZone);

    Serial.print("locked: ");
    Serial.print(arena.containers[currentZone].locked[0]);
    Serial.print(" ");
    Serial.println(arena.containers[currentZone].locked[1]);

    Serial.print("clawSide: ");
    Serial.print(arena.containers[currentZone].clawSide[0]);
    Serial.print(" ");
    Serial.println(arena.containers[currentZone].clawSide[1]);

    Serial.print("getCurrentPile: ");
    Serial.println(arena.containers[currentZone].getCurrentPile());

    // Se estiver na pilha 1
    if (arena.containers[currentZone].getCurrentPile()) {
        Serial.println("Estou na pilha 1");
        // Pilha 1
        Serial.println("backwardUntilBlackLine in goToNextPile");
        backwardUntilBlackLine();
        forward(2, 200);

        if (currentZone == 0) {
            
            if (!arena.containers[1].isEmpty(clawSide)) {
                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                currentZone = 1;
            } else if (!arena.containers[2].isEmpty(clawSide)){

                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                forward(1, 200);
                sidewaysLeft(1, 200);

                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                currentZone = 2;
            } else 
                stop();

        } else if (currentZone == 1) {

            if (!arena.containers[2].isEmpty(clawSide)) {
                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                currentZone = 2;
            } else if (!arena.containers[0].isEmpty(clawSide)) {
                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                currentZone = 0;
            } else 
                stop();


        } else if (currentZone == 2) {
            
            if (!arena.containers[1].isEmpty(clawSide)) {
                forward(1, 200);
                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight(); 

                
                currentZone = 1;

            } else {
                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();   
             
                forward(1, 200);
                sidewaysRight(1, 200);

                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                currentZone = 0;
            }
        }

    } else {
        Serial.println("Estou na pilha 0");
        // Pilha 0
        while (containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }

        while (!containerSensorB.getValue()) {
            if (sensorFL.getValue())
                rotateLeft(0, 150);
            else if (sensorFR.getValue())
                rotateRight(0, 150);
            else
                forward(0, 150);
        }
        
        // backward(1, 150);
        stop();
    }

    followLineUntilContainer();
    checkColor();
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
    Ship destination;
    if(currentDestination == Green)
        destination = arena.greenShip;
    else if(currentDestination == Blue)
        destination = arena.blueShip;

    // Se estiver no lado do navio
    if (destination.currentPile > 0 and destination.currentHeight != 1) {
        if (currentDestination == Blue) {
            sidewaysRight(5, 255);
            rotateLeft(32, 255);

            while (!sensorFL.getValue() or !sensorFR.getValue()) forward();
            while (sensorFL.getValue() and sensorFR.getValue()) forward();

            forward(1, 200);


            if (!arena.containers[1].isEmpty(clawSide)) {
                currentZone = 1;
                alignBetweenContainers();
            } else if (!arena.containers[2].isEmpty(clawSide)) {
                currentZone = 2;
                alignBetweenContainers();
            } else if (!arena.containers[0].isEmpty(clawSide)) {
                currentZone = 0;
                alignBetweenContainers();
            }


            // if (arena.containers[currentZone].isEmpty(clawSide)) {
            //     currentZone = 0;
            //     alignBetweenContainers();
            // } else if (currentZone != 0 and arena.containers[1].isEmpty(clawSide)){
            //     currentZone = 1;
            //     alignBetweenContainers();
            // } else     
            //     alignBetweenContainers();

            stop();

        } else if (currentDestination == Green) {
            sidewaysRight(5, 255);

            while (!sensorFL.getValue() or !sensorFR.getValue()) forward();
            while (sensorFL.getValue() and sensorFR.getValue()) forward();

            forward(1, 200);


            if (!arena.containers[2].isEmpty(clawSide)) {
                currentZone = 2;
                alignBetweenContainers();
            } else if (!arena.containers[1].isEmpty(clawSide)) {
                currentZone = 1;
                alignBetweenContainers();
            } else if (!arena.containers[0].isEmpty(clawSide)) {
                currentZone = 0;
                alignBetweenContainers();
            }

            // if (arena.containers[currentZone].isEmpty(clawSide)) {
            //     currentZone = 0;
            //     alignBetweenContainers();
            // } else if (currentZone != 0){
            //     currentZone = 2;
            //     alignBetweenContainers();
            // } else 
            //     alignBetweenContainers();          

            stop();
        }

    } else  {
        // Frente do navio
        if (currentDestination == Blue) {
            while (!sensorFRR.getValue()) sidewaysRight();
            while (sensorFRR.getValue()) sidewaysRight();

            rotateRight(15);
            forward(2, 200);

            if (!arena.containers[1].isEmpty(clawSide)) {
              
                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                forward(1, 200);

                currentZone = 1;

            } else if (!arena.containers[0].isEmpty(clawSide)) {
                while (!sensorFR.getValue()) sidewaysLeft();
                while (sensorFR.getValue()) sidewaysLeft();

                forward(1, 200);

                currentZone = 0;

            } else if (!arena.containers[1].isEmpty(clawSide)) {
                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                forward(1, 200);

                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();

                forward(1, 200);

                currentZone = 1;
                
            } else 
                stop();

            /*
            if (arena.containers[currentZone].isEmpty(clawSide) or 
                arena.containers[1].isEmpty(clawSide)) {
                currentZone = 0;
                
                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

            } else {
                currentZone = 1;

                while (!sensorFL.getValue()) sidewaysLeft();
                while (sensorFL.getValue()) sidewaysLeft();
            } 
            forward(3, 150);
            */

            stop();

        } else if (currentDestination == Green) {
            while (!sensorFRR.getValue()) sidewaysRight();
            while (sensorFRR.getValue()) sidewaysRight();

            rotateRight(15);
            forward(2, 200);

            if (!arena.containers[2].isEmpty(clawSide)) {
                
                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                forward(1, 200);

                currentZone = 2;

            } else if (!arena.containers[1].isEmpty(clawSide)) {

                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                forward(1, 200);

                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                forward(1, 200);

                currentZone = 1;

            } else if (!arena.containers[0].isEmpty(clawSide)) {

                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                forward(1, 200);

                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                forward(1, 200);

                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();

                forward(1, 200);

                currentZone = 0;

            } else 
                stop();

            /*
            if (arena.containers[currentZone].isEmpty(clawSide)) {
                // Pilhas da zona 1 estão vazias
                if (arena.containers[1].isEmpty(clawSide)) {
                    currentZone = 0;
                    // alignBetweenContainers();
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();

                    sidewaysRight(1, 255);
                    forward(1, 255);
                    
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();

                    sidewaysRight(1, 255);
                    forward(1, 255);
                    
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();
                } else {
                    currentZone = 1;
                    
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();

                    forward(1, 255);
                    sidewaysRight(1, 255);
                    
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();

                    stop();
                }
                

            } else {

                // Pilhas da zona 2 estão vazias
                if (arena.containers[2].isEmpty(clawSide)) {
                    currentZone = 0;
                    // alignBetweenContainers();
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();

                    sidewaysRight(1, 255);
                    forward(1, 255);
                    
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();

                    sidewaysRight(1, 255);
                    forward(1, 255);
                    
                    while (!sensorFR.getValue()) sidewaysRight();
                    while (sensorFR.getValue()) sidewaysRight();
                }

                currentZone = 2;
                
                while (!sensorFR.getValue()) sidewaysRight();
                while (sensorFR.getValue()) sidewaysRight();
            } 

            forward(3, 150);
            */

            stop();
        }
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

void Robot::checkColor() {
    // Backward
    frontLeft.backward(25, 255);
    frontRight.backward(25, 255);
    backLeft.backward(25, 255);
    backRight.backward(25, 255);

    uint8_t containerHeight = arena.containers[currentZone].getHeight(clawSide);

    claw.goToContainer(containerHeight + 0.5);

    currentDestination = colorSensor.readColor();

    if (currentDestination == Red) {
        Serial.println("Encontrei vermelho, vou pra outra pilha");
        arena.containers[currentZone].lockPile();
        claw.goToContainer(5.5);
        forward(1, 200);
        goToNextPile();
    } 
}

void Robot::testMoviments() {
    forward(20);
    delay(10);
    backward(20);
    delay(10);
    sidewaysRight(20);
    delay(1000);
    sidewaysLeft(20);
    delay(10);
    rotateLeft(20);
    delay(10);
    rotateRight(20);
    delay(10);
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