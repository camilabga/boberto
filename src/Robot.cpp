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
}

void Robot::forward(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.forward(goal);
}

void Robot::backward(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.backward(goal);
    backLeft.backward(goal);
    backRight.backward(goal);
}

void Robot::sidewaysRight(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.backward(goal);
    backLeft.backward(goal);
    backRight.forward(goal);
}

void Robot::sidewaysLeft(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.forward(goal);
    backLeft.forward(goal);
    backRight.backward(goal);
}

void Robot::rotateLeft(unsigned long int goal) {
    frontLeft.backward(goal);
    frontRight.forward(goal);
    backLeft.backward(goal);
    backRight.forward(goal);
}

void Robot::rotateRight(unsigned long int goal) {
    frontLeft.forward(goal);
    frontRight.backward(goal);
    backLeft.forward(goal);
    backRight.backward(goal);
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

Robot::~Robot() {}