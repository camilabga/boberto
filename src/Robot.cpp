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

void Robot::forward(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.forward(goal);
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

void Robot::followLine() {
    double start = millis();
    while (millis() - start < 2370) {
        Serial.print("TIME: ");
        Serial.println(millis() - start);
        if (sensorFL.getValue()) {
            rotateLeft();
        } else if (sensorFR.getValue()) {
            rotateRight();
        } else {
            forward();
        }
    }
}
void Robot::alignBetweenContainers() {
    Serial.println("Sideways");
    sidewaysRight();
    while (!sensorFR.getValue()) {
        delay(1);
    }
    while (sensorFR.getValue()) {
        delay(1);
    }
    // stop();
    followLine();
    /*
    sidewaysLeft();
    while (!sensorFR.getValue() || !sensorBR.getValue()) {
        Serial.print(sensorFL.getValue());
        Serial.println(sensorFL.getValue());
    }*/

    stop();

    delay(5765765);
}

Robot::~Robot() {}