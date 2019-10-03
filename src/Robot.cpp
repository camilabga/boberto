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
}

Robot::~Robot() {}

void Robot::begin() {
    // Seta a posição inicial da garra
    claw.goHome();
    claw.goToContainer(5.5);
    
    lidar.begin();

    // Calibra o sensor de cor
    // colorSensor.init();
    // colorSensor.ledOn();
    // colorSensor.calibrate();
}

void Robot::forward(uint8_t goal, int16_t vel) {
    if(!goal) {
        frontLeft.forward(0, vel);
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.forward(0, vel); 
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.backward(0, vel);
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.backward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.forward(0, vel);
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.forward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.backward(0, vel);
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.backward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.backward(0, vel);
        frontRight.forward(0, vel);
        backLeft.backward(0, vel);
        backRight.forward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.forward(0, vel);
        frontRight.backward(0, vel);
        backLeft.forward(0, vel);
        backRight.backward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.forward(0, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.forward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.stop();
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.stop();
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.stop();
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.stop();
    } else {
        for(byte i = 0; i < goal; i++) {
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
    if(!goal) {
        frontLeft.backward(0, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.backward(0, vel);
    } else {
        for(byte i = 0; i < goal; i++) {
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

void Robot::stop() {
    frontLeft.stop();
    frontRight.stop();
    backLeft.stop();
    backRight.stop();
}

// Movimentação da garra
void Robot::catchContainer(uint8_t container) {
    claw.extend();
    claw.goToContainer(container);
    claw.goToContainer(container + 0.5);
    claw.ajustContainer();
    claw.goToContainer(5.5);
}

void Robot::catchContainer() {
    uint8_t container = arena.containers[currentZone].getHeight(clawSide);
    claw.extend();
    claw.goToContainer(container);
    claw.goToContainer(container + 0.5);
    claw.goToContainer(5.5);

    //arena.containers[currentZone].updateHeight(clawSide);
    //if (arena.containers[currentZone].isEmpty(clawSide)) {
    //    currentZone++;
    //    if (currentZone == 3) 
    //        currentZone = 0;
    //}
}
/*
void Robot::releaseContainer(uint8_t container) {
    claw.goToContainer(container);
    claw.retract();
    claw.goToContainer(5.5);
}*/

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
    while (!sensorFL.getValue() || !sensorFR.getValue()) {
        delay(1);
    }
    while (sensorFL.getValue() && sensorFR.getValue()) {
        delay(1);
    }
    delay(200);
    stop();

    /*
    Serial.print("Front Left: ");
    Serial.println(sensorFL.getValue());

    Serial.print("Front Right: ");
    Serial.println(sensorFR.getValue());

    Serial.print("\n");
    */
}

void Robot::findBlueLine() {
    sidewaysLeft();
    while (blueSensorF.getValue() && blueSensorB.getValue()) {
        delay(1);
    }

    stop();
}

void Robot::followLineUntilGap() {
    // Anda até encontrar o primeiro container
    uint16_t dist = lidar.getDistance();
    while (dist > 120) {
        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward(0, 100);
            
        delay(20);
        dist = lidar.getDistance();
        //Serial.println(dist);
    }

    // Anda até sair do container
    dist = lidar.getDistance();
    while (dist < 120) {
        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward(0, 100);
            
        delay(20);
        dist = lidar.getDistance();
        //Serial.println(dist);
    }    

    stop();
}

void Robot::followHorizontalRight() {
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
    
    stop();
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

    stop();
}

void Robot::alignBetweenContainers(uint8_t zone) {
    switch (zone) {
        case 0:
            /* decidir dps */
            stop();
            break;
        case 1:
            sidewaysRight(); 

            while (!sensorFR.getValue()) delay(1);

            while (sensorFR.getValue()) delay(1);

            break;
        case 2:
            sidewaysLeft();

            while (!sensorFL.getValue()) delay(1);

            while (sensorFL.getValue()) delay(1);

            break;
        default:
            stop();
            break;
    }

    stop();
}

void Robot::alignWithShip(){
    while (!blueSensorF.getValue() or !blueSensorB.getValue()) {
        if (blueSensorB.getValue()) 
            rotateLeft(0, 150);
        else if(blueSensorF.getValue())
            rotateRight(0, 150);
        else if(!blueSensorF.getValue() and !blueSensorB.getValue()) 
            sidewaysLeft(0, 150);
    }

    stop();
}

void Robot::backwardUntilBlackLine() {
    backward();

    while (!sensorFL.getValue() || !sensorFR.getValue()) delay(1);

    stop();
}

void Robot::goToBlueShip() {
    if (arena.side) {
        if (currentZone == 1) {
            rotateLeft(16);

            while (!sensorFR.getValue()) 
                sidewaysRight(0, 200);

            while (sensorFR.getValue())
                sidewaysRight(0, 200);
            
            sidewaysRight(1, 200);
            
            followHorizontalRight();

            backward(5, 200);

            while (!sensorFRR.getValue()) 
                sidewaysLeft();

            while (sensorFRR.getValue())
                sidewaysLeft();

            sidewaysLeft(3);

            alignWithShip();                 

        } else if (currentZone == 2) {
            rotateLeft(16);

            while (!sensorFR.getValue()) 
                sidewaysRight(0, 200);

            while (sensorFR.getValue())
                sidewaysRight(0, 200);
            
            sidewaysRight(1, 200);

            followHorizontalRight();
            followHorizontalRight();

            backward(5, 200);

            while (!sensorFRR.getValue()) 
                sidewaysLeft();

            while (sensorFRR.getValue())
                sidewaysLeft();

            sidewaysLeft(3);

            alignWithShip();
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
        if (currentZone == 1) {
           rotateLeft(16);

            while (!sensorFR.getValue()) 
                sidewaysRight(0, 200);

            while (sensorFR.getValue())
                sidewaysRight(0, 200);
            
            sidewaysRight(1, 200);
            
            followHorizontalLeft();
            followHorizontalLeft();

            backward(5, 200);

            while (!sensorFRR.getValue()) 
                sidewaysLeft();

            while (sensorFRR.getValue())
                sidewaysLeft();

            sidewaysLeft(3);
            
            alignWithShip();             

        } else if (currentZone == 2){
            rotateLeft(16);

            while (!sensorFR.getValue()) 
                sidewaysRight(0, 200);

            while (sensorFR.getValue())
                sidewaysRight(0, 200);
            
            sidewaysRight(1, 200);
            
            followHorizontalLeft();

            backward(5, 200);

            while (!sensorFRR.getValue()) 
                sidewaysLeft();

            while (sensorFRR.getValue())
                sidewaysLeft();

            sidewaysLeft(3);
            
            alignWithShip();  
        }
    } else { 
        rotateLeft(35);
        followHorizontalRight();
        findBlueLine();
        alignWithShip();
    }
}

void Robot::goToContainerZone(){
    findBlackLine();
    alignBetweenContainers(currentZone);
    followLineUntilGap();
}

void Robot::calibrateColorSensor() {
    colorSensor.ledOn();
    colorSensor.calibrate();
}

void Robot::testMoviments() {
    forward(10);
    delay(1000);
    backward(10);
    delay(1000);
    sidewaysRight(10);
    delay(1000);
    sidewaysLeft(10);
    delay(1000);
    rotateLeft(10);
    delay(1000);
    rotateRight(10);
    delay(1000);

}

void Robot::testClaw() {
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
    int color = colorSensor.readColor();

    Serial.print("Color: ");
    switch (color) {
        case 0:
            Serial.println("Red");
            break;

        case 1:
            Serial.println("Green");
            break;

        case 2:
            Serial.println("Blue");
            break;

        default:
            Serial.println("404 Color Not Found");
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

    start = millis();
    bool gap = lidar.getContainerGap();
    end = millis();

    Serial.print("Container Gap: ");
    Serial.print(gap ? "Yes" : "No");
    Serial.print(" ");
    Serial.print(end - start);
    Serial.print("ms\n\n");
}

void Robot::chooseContainerDestination() {
    // currentDestination = colorSensor.readColor();
    currentDestination = Green;
    // currentDestination = Blue;
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
    if(currentDestination == Blue) {
        while (!sensorFRR.getValue())
            sidewaysRight();

        while (sensorFRR.getValue())
            sidewaysRight();

        rotateRight(15);

        while (!sensorFL.getValue())
            sidewaysLeft();
        
        while (sensorFL.getValue())
            sidewaysLeft();

        currentZone = 1;

    } else if (currentDestination == Green) {
        while (!sensorFRR.getValue())
            sidewaysRight();

        while (sensorFRR.getValue())
            sidewaysRight();

        rotateRight(15);

        while (!sensorFR.getValue())
            sidewaysRight();
        
        while (sensorFR.getValue())
            sidewaysRight();

        forward(1, 150);

        currentZone = 2;
    }
}