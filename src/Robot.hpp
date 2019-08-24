#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Arduino.h"
#include "Sensor.hpp"

class Motor {
 public:
  int encoderPin;
  int pin1, pin2;

  volatile long unsigned int cont;
  int goal;

  int side;

  Motor();
  ~Motor();

  void setupInterruptHandler(void (*ISR)(void), int value);
  void handleInterrupt(void);

  void setPins(int _encoderPin, int _pin1, int _pin2);

  void forward(long int _goal);
  void forward();
  void forward(uint8_t vel);
  void backward(long int _goal);
  void backward();
  void backward(uint8_t vel);
  void stop();
};

class Robot {
 public:
  Motor frontLeft, frontRight, backLeft, backRight;
  Sensor sensorFL, sensorFR, sensorBL, sensorBR;

  Robot();

  void stop();
  void forward(long int goal);
  void forward(uint8_t vel);
  void forward();

  void backward(long int goal);
  void backward(uint8_t vel);
  void backward();

  void sidewaysRight(long int goal);
  void sidewaysRight(uint8_t vel);
  void sidewaysRight();

  void sidewaysLeft(long int goal);
  void sidewaysLeft(uint8_t vel);
  void sidewaysLeft();

  void rotateLeft(long int goal);
  void rotateLeft(uint8_t vel);
  void rotateLeft();

  void rotateRight(long int goal);
  void rotateRight(uint8_t vel);
  void rotateRight();

  void moveRightForward(long int goal);
  void moveRightBackward(long int goal);
  void moveLeftForward(long int goal);
  void moveLeftBackward(long int goal);

  /*
  void rotateLeft();
  void rotateRight();
  void moveRightForward();
  void moveRightBackward();
  void moveLeftForward();
  void moveLeftBackward();*/

  void findBlackLine();
  void alignBetweenContainers();

  ~Robot();
};

#endif  // ROBOT_HPP