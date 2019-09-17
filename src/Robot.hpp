#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>

#include "Claw.hpp"
#include "ColorSensor.hpp"
#include "DistanceSensor.hpp"
#include "Motor.hpp"
#include "Sensor.hpp"

class Robot {
 private:
  Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};
  Claw claw{26, 27, 28, 29, 30};

  Sensor sensorFL, sensorFR, sensorBL, sensorBR;
  Sensor sensorFLL, sensorFRR;  // Sensores mais externos
  Sensor sensorSB, sensorSF;

  DistanceSensor lidar;
  ColorSensor colorSensor{32};

 public:
  Robot();
  ~Robot();

  void stop();
  void forward(unsigned long int goal = 0, int16_t vel = 255);

  void begin();

  void backward(unsigned long int goal = 0, int16_t vel = 255);

  void sidewaysRight(unsigned long int goal = 0, int16_t vel = 255);
  // void sidewaysRight(unsigned char vel);
  void sidewaysRight();

  void sidewaysLeft(unsigned long int goal = 0, int16_t vel = 255);
  // void sidewaysLeft(unsigned char vel);
  void sidewaysLeft();

  void rotateLeft(unsigned long int goal = 0, int16_t vel = 255);
  // void rotateLeft(unsigned char vel);
  void rotateLeft();

  void rotateRight(unsigned long int goal = 0, int16_t vel = 255);
  // void rotateRight(unsigned char vel);
  void rotateRight();

  void moveRightForward(unsigned long int goal = 0, int16_t vel = 255);
  void moveRightForward();

  void moveRightBackward(unsigned long int goal = 0, int16_t vel = 255);
  void moveRightBackward();

  void moveLeftForward(unsigned long int goal = 0, int16_t vel = 255);
  void moveLeftForward();

  void moveLeftBackward(unsigned long int goal = 0, int16_t vel = 255);
  void moveLeftBackward();

  // Movimentação da garra
  void catchContainer(uint8_t container);
  void releaseContainer(uint8_t container);

  void findBlackLine();
  void alignBetweenContainers();
  void followLineUntilGap();
  void followHorizontalRight();
  void followHorizontalLeft();
  void backwardUntilBlackLine();

  void goToBLueShip(uint8_t container);
  void goToGreenShip(uint8_t container);

  // Sensor de cor
  void calibrateColorSensor();

  // Sanity check stuff
  void testMoviments();
  void testClaw();
  void testColorSensor();
  void testDistanceSensor();
};

#endif  // ROBOT_HPP