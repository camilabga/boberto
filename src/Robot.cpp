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

  sensorSB.setPin(35);
  sensorSF.setPin(34);

  sensorFLL.setPin(36);
  sensorFRR.setPin(34);
}

Robot::~Robot() {}

void Robot::forward(unsigned long int goal) {
  frontLeft.forward(goal);
  frontRight.forward(goal);
  backLeft.forward(goal);
  backRight.forward(goal);
}

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
}

/*
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
void Robot::rotateRight(unsigned long int goal) {
  frontLeft.backward(goal);
  frontRight.forward(goal);
  backLeft.backward(goal);
  backRight.forward(goal);
}
/*
void Robot::rotateRight(unsigned char vel) {
    frontLeft.backward(vel);
    frontRight.forward(vel);
    backLeft.backward(vel);
    backRight.forward(vel);
}
*/
void Robot::rotateRight() {
  frontLeft.backward();
  frontRight.forward();
  backLeft.backward();
  backRight.forward();
}

void Robot::rotateLeft(unsigned long int goal) {
  frontLeft.forward(goal);
  frontRight.backward(goal);
  backLeft.forward(goal);
  backRight.backward(goal);
}
/*
void Robot::rotateLeft(unsigned char vel) {
    frontLeft.forward(vel);
    frontRight.backward(vel);
    backLeft.forward(vel);
    backRight.backward(vel);
}
*/
void Robot::rotateLeft() {
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

void Robot::moveRightForward() {
  frontLeft.forward();
  frontRight.stop();
  backLeft.stop();
  backRight.forward();
}

void Robot::moveRightBackward() {
  frontLeft.stop();
  frontRight.backward();
  backLeft.backward();
  backRight.stop();
}

void Robot::moveLeftForward() {
  frontLeft.stop();
  frontRight.forward();
  backLeft.forward();
  backRight.stop();
}

void Robot::moveLeftBackward() {
  frontLeft.backward();
  frontRight.stop();
  backLeft.stop();
  backRight.backward();
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

void Robot::calibrateColorSensor() {
  colorSensor.ledOn();
  colorSensor.calibrate();
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
  rotateLeft();

  delay(1830);

  stop();

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