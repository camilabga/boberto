#include "Robot.hpp"

Robot::Robot() {
    // Inicia os pinos dos motores
    frontLeft.setPins(2, 5, 4);
    frontRight.setPins(3, 6, 7);
    backLeft.setPins(18, 8, 9);
    backRight.setPins(19, 10, 11);

    frontLeft.begin();
    frontRight.begin();
    backLeft.begin();
    backRight.begin();

    sensorFL.setPin(13);
    sensorFR.setPin(12);
    sensorBL.setPin(22);
    sensorBR.setPin(24);
}

Robot::~Robot() {}

void Robot::forward(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.forward(goal);
}

void Robot::begin() {
    lidar.begin();

    // Seta a posição inicial da garra
    claw.goHome();
    claw.goToContainer(5.5);
}

/*Interrupts are meanless here*/
void Robot::forward() {
    frontLeft.forward();
    frontRight.forward();
    backLeft.forward();
    backRight.forward();
}

/* Interrupts are meanless here
void Robot::forward(unsigned char vel) {
    frontLeft.forward(vel);
    frontRight.forward(vel);
    backLeft.forward(vel);
    backRight.forward(vel);
}*/

void Robot::backward(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.backward(goal);
    backLeft.backward(goal);
    backRight.backward(goal);
}

/* Interrupts are meanless here*/
void Robot::backward() {
    frontLeft.backward();
    frontRight.backward();
    backLeft.backward();
    backRight.backward();
}
/*
void Robot::backward(unsigned char vel) {
    frontLeft.backward(vel);
    frontRight.backward(vel);
    backLeft.backward(vel);
    backRight.backward(vel);
}*/

void Robot::sidewaysLeft(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.backward(goal);
    backLeft.backward(goal);
    backRight.forward(goal);
} /*
 void Robot::sidewaysLeft(unsigned char vel) {
     frontLeft.forward(vel);
     frontRight.backward(vel);
     backLeft.backward(vel);
     backRight.forward(vel);
 }*/
void Robot::sidewaysLeft() {
    frontLeft.forward();
    frontRight.backward();
    backLeft.backward();
    backRight.forward();
}

void Robot::sidewaysRight(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.backward(goal);
}
void Robot::sidewaysRight() {
    frontLeft.backward();
    frontRight.forward();
    backLeft.forward();
    backRight.backward();
}
/*
void Robot::sidewaysRight(unsigned char vel) {
    frontLeft.backward(vel);
    frontRight.forward(vel);
    backLeft.forward(vel);
    backRight.backward(vel);
}
*/
void Robot::rotateLeft(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.forward(goal);
    backLeft.backward(goal);
    backRight.forward(goal);
}
/*
void Robot::rotateLeft(unsigned char vel) {
    frontLeft.backward(vel);
    frontRight.forward(vel);
    backLeft.backward(vel);
    backRight.forward(vel);
}
*/
void Robot::rotateLeft() {
    frontLeft.backward();
    frontRight.forward();
    backLeft.backward();
    backRight.forward();
}

void Robot::rotateRight(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.backward(goal);
    backLeft.forward(goal);
    backRight.backward(goal);
}
/*
void Robot::rotateRight(unsigned char vel) {
    frontLeft.forward(vel);
    frontRight.backward(vel);
    backLeft.forward(vel);
    backRight.backward(vel);
}
*/
void Robot::rotateRight() {
    frontLeft.forward();
    frontRight.backward();
    backLeft.forward();
    backRight.backward();
}

void Robot::moveRightForward(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.stop();
    backLeft.stop();
    backRight.forward(goal);
}

void Robot::moveRightBackward(unsigned long int goal) {
    frontLeft.stop();
    frontRight.backward(goal);
    backLeft.backward(goal);
    backRight.stop();
}

void Robot::moveLeftForward(unsigned long int goal) {
    frontLeft.stop();
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.stop();
}

void Robot::moveLeftBackward(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.stop();
    backLeft.stop();
    backRight.backward(goal);
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
}

void Robot::followLineUntilGap() {
    Serial.println("Entrei");

    while (lidar.getContainerGap()) {
        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward();

        Serial.println(lidar.getDistance());
    }
    Serial.println("Entrei");
    while (!lidar.getContainerGap()) {
        if (sensorFL.getValue())
            rotateLeft();
        else if (sensorFR.getValue())
            rotateRight();
        else
            forward();
        Serial.println(lidar.getDistance());
    }

    stop();
}

void Robot::alignBetweenContainers() {
    Serial.println("Sideways");
    sidewaysRight();

    while (!sensorFR.getValue()) delay(1);

    while (sensorFR.getValue()) delay(1);

    stop();
}

void Robot::testMoviments() {
    forward(3000);
    delay(1000);
    backward(3000);
    delay(1000);
    sidewaysRight(3000);
    delay(1000);
    sidewaysLeft(3000);
    delay(1000);
}

void Robot::testClaw() {
    catchContainer(1);
    delay(1000);
    releaseContainer(0);
    delay(1000);
}