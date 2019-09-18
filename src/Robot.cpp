#include "Robot.hpp"

Robot::Robot() {
    // Inicia os pinos dos motores
    frontLeft.setPins(3, 6, 7);
    frontRight.setPins(2, 5, 4);
    backLeft.setPins(18, 10, 11);
    backRight.setPins(19, 8, 9);

    frontLeft.begin();
    frontRight.begin();
    backLeft.begin();
    backRight.begin();

    sensorFL.setPin(13);
    sensorFR.setPin(12);
    sensorBL.setPin(22);
    sensorBR.setPin(24);

    sensorSB.setPin(35);
    sensorSF.setPin(34);

    sensorFLL.setPin(36);
    sensorFRR.setPin(34);
}

Robot::~Robot() {}

void Robot::begin() {
    // Seta a posição inicial da garra
    claw.goHome();
    claw.goToContainer(5.5);

    lidar.begin();

    // Calibra o sensor de cor
    colorSensor.init();
    colorSensor.ledOn();
    colorSensor.calibrate();
}

void Robot::forward(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.forward(100, vel);
        frontRight.forward(100, vel);
        backLeft.forward(100, vel);
        backRight.forward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::backward(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.backward(100, vel);
        frontRight.backward(100, vel);
        backLeft.backward(100, vel);
        backRight.backward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::sidewaysLeft(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.forward(100, vel);
        frontRight.backward(100, vel);
        backLeft.backward(100, vel);
        backRight.forward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::sidewaysRight(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.backward(100, vel);
        frontRight.forward(100, vel);
        backLeft.forward(100, vel);
        backRight.backward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::rotateRight(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.backward(100, vel);
        frontRight.forward(100, vel);
        backLeft.backward(100, vel);
        backRight.forward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::rotateLeft(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.forward(100, vel);
        frontRight.backward(100, vel);
        backLeft.forward(100, vel);
        backRight.backward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::moveRightForward(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.forward(100, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.forward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::moveRightBackward(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.stop();
        frontRight.backward(100, vel);
        backLeft.backward(100, vel);
        backRight.stop();

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::moveLeftForward(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.stop();
        frontRight.forward(100, vel);
        backLeft.forward(100, vel);
        backRight.stop();

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
    }
}

void Robot::moveLeftBackward(uint8_t goal, int16_t vel) {
    for(byte i = 0; i < goal; i++) {
        frontLeft.backward(100, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.backward(100, vel);

        while (frontLeft.getFinished() and frontRight.getFinished() and
            backLeft.getFinished() and backRight.getFinished()) {
            delay(1);
        }
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

void Robot::releaseContainer(uint8_t container) {
    claw.goToContainer(container);
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

void Robot::followLineUntilGap() {
    // Anda até encontrar o primeiro container
    while (lidar.getContainerGap()) {
        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward();

        // Serial.println(lidar.getDistance());
    }

    // Anda até sair do container
    while (!lidar.getContainerGap()) {
        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward();
        // Serial.println(lidar.getDistance());
    }

    stop();
}

void Robot::followHorizontalRight() {
    // Anda até encontrar o primeiro container
    forward();
    while ((!sensorFLL.getValue() || !sensorFRR.getValue())) {
        delay(1);
    }

    stop();
    // delay(2000);
    long int luiz = 0;
    do {
        Serial.print(sensorFLL.getValue());
        Serial.print('\t');
        Serial.print(sensorFL.getValue());
        Serial.print('\t');
        Serial.print(sensorFR.getValue());
        Serial.print('\t');
        Serial.println(sensorFRR.getValue());
        if (!sensorFLL.getValue() && sensorFRR.getValue()) {
            if (sensorFL.getValue()) {
                rotateRight();
            } else {
                rotateLeft();
            }
        } else if (!sensorFRR.getValue() && sensorFLL.getValue()) {
            if (sensorFL.getValue()) {
                rotateLeft();
            } else {
                rotateRight();
            }

        } else if ((!sensorFRR.getValue() && !sensorFLL.getValue()) &&
                   ((!sensorFR.getValue() && !sensorFL.getValue()))) {
            backward();

        } else if ((!sensorFRR.getValue() && !sensorFLL.getValue()) &&
                   ((sensorFR.getValue() && sensorFL.getValue()))) {
            forward();
            delay(70);

        } else {
            sidewaysRight();
            delay(50);
        }

        luiz++;
    } while (luiz < 200000);
}

void Robot::followHorizontalLeft() {
    // Anda até encontrar o primeiro container
    /*
    forward();
    while ((!sensorFLL.getValue() || !sensorFRR.getValue())) {
      delay(1);
    }

    stop();
    // delay(2000);
    */

    while (!sensorSB.getValue()) {
        if (sensorFL.getValue() && sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() && sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() && sensorBL.getValue())
            moveLeftForward();
        else if (sensorFR.getValue() && sensorBR.getValue())
            moveRightForward();
        else
            forward();
    }
    while (sensorSB.getValue()) {
        if (sensorFL.getValue() && sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() && sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() && sensorBL.getValue())
            moveLeftForward();
        else if (sensorFR.getValue() && sensorBR.getValue())
            moveRightForward();
        else
            forward();
    }
    while (!sensorSB.getValue()) {
        if (sensorFL.getValue() && sensorBR.getValue())
            rotateLeft();
        else if (sensorFR.getValue() && sensorBL.getValue())
            rotateRight();
        else if (sensorFL.getValue() && sensorBL.getValue())
            moveLeftForward();
        else if (sensorFR.getValue() && sensorBR.getValue())
            moveRightForward();
        else
            forward();
    }
    stop();
}

void Robot::alignBetweenContainers() {
    sidewaysRight();

    while (!sensorFR.getValue()) delay(1);

    while (sensorFR.getValue()) delay(1);

    stop();
}

void Robot::backwardUntilBlackLine() {
    backward();

    while (!sensorFL.getValue() || !sensorFR.getValue()) delay(1);

    stop();
}

void Robot::goToBLueShip(uint8_t container) {
    forward();

    delay(300);

    stop();

    sidewaysRight();

    delay(1414);

    stop();

    rotateLeft();

    delay(1830);

    stop();

    sidewaysLeft();

    delay(650);

    stop();

    releaseContainer(container);

    sidewaysRight();

    delay(650);

    stop();

    rotateRight();

    delay(1830);

    stop();

    sidewaysLeft();

    delay(1414);

    stop();
}

void Robot::goToGreenShip(uint8_t container) {
    for (uint8_t i = 0; i < 35; i++) rotateLeft(100);

    alignBetweenContainers();

    followHorizontalLeft();

    forward();

    delay(600);

    stop();

    sidewaysLeft();

    delay(1100);

    stop();

    releaseContainer(container);

    sidewaysRight();

    delay(650);

    stop();

    rotateRight();

    delay(1830);

    stop();

    sidewaysRight();

    delay(1414);

    stop();
}

void Robot::calibrateColorSensor() {
    colorSensor.ledOn();
    colorSensor.calibrate();
}

void Robot::testMoviments() {
    forward(1000);
    delay(3000);
    backward(1000);
    delay(3000);
    sidewaysRight(1000);
    delay(3000);
    sidewaysLeft(1000);
    delay(3000);
}

void Robot::testClaw() {
    catchContainer(1);
    delay(1000);
    releaseContainer(1);
    delay(1000);
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
    Serial.print("Distance: ");
    Serial.println(lidar.getDistance());
}