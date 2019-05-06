#include "Robot.hpp"

Robot::Robot() {
    this->frontLeft = {0 , 5, 6};
    this->frontRight = {0 , 3, 4};
    this->backLeft = {0 , 7, 8};
    this->backRight = {0 , 9, 10};
}

void Robot::forward() {
    digitalWrite(frontLeft.pin1, HIGH);
    digitalWrite(frontLeft.pin2, LOW);

    digitalWrite(frontRight.pin1, HIGH);
    digitalWrite(frontRight.pin2, LOW);

    digitalWrite(backLeft.pin1, HIGH);
    digitalWrite(backLeft.pin2, LOW);

    digitalWrite(backRight.pin1, HIGH);
    digitalWrite(backRight.pin2, LOW);    
}

Robot::~Robot() {
}