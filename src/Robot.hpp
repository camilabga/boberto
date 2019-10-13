#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>

#include "Claw.hpp"
// #include "ColorSensor.hpp"
#include "ColorSensorAnalog.hpp"
#include "DistanceSensor.hpp"
#include "Motor.hpp"
#include "LineSensor.hpp"
#include "Arena.hpp"

class Robot {
	private:
		Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};
		
		Claw claw{50 , 52, 13, 11, 12, 53};

		// Sensores Frontais
		LineSensor sensorFL, sensorFR;
		// Sensores Frontais mais externos
		LineSensor sensorFLL, sensorFRR;
		// Sensores Traseiros
		LineSensor sensorBL, sensorBR;
		// Sensores Laterais
		LineSensor sensorSB, sensorSF;
		//Sensores de Azul
		LineSensor blueSensorF, blueSensorB;

		DistanceSensor lidar;

		// ColorSensor colorSensor{33};
		ColorSensorAnalog colorSensor{33, 0};

		Arena arena;
		uint8_t currentZone = 0;

		COLOR currentDestination = Blue;

	public:
		Robot();
		~Robot();

		void begin();

		void stop();

		void forward(uint8_t goal = 0, int16_t vel = 255);
		void backward(uint8_t goal = 0, int16_t vel = 255);

		void sidewaysRight(uint8_t goal = 0, int16_t vel = 255);		
		void sidewaysLeft(uint8_t goal = 0, int16_t vel = 255);

		void rotateLeft(uint8_t goal = 0, int16_t vel = 255);
		void rotateRight(uint8_t goal = 0, int16_t vel = 255);

		void moveRightForward(uint8_t goal = 0, int16_t vel = 255);
		void moveRightBackward(uint8_t goal = 0, int16_t vel = 255);

		void moveLeftForward(uint8_t goal = 0, int16_t vel = 255);
		void moveLeftBackward(uint8_t goal = 0, int16_t vel = 255);

		void smoothRotateLeft();
		void smoothRotateRight();

		// Movimentação da garra
		// void catchContainer(uint8_t container);
		void catchContainer();
		void releaseContainer(COLOR color);

		void findBlackLine();
		void findBlueLine();

		void alignBetweenContainers();
		void alignWithShip();
		void alignWithContainersPile();

		void followLineUntilGap();
		void followHorizontalRight();
		void followHorizontalLeft();
		
		void goToContainerZone();
		void goToBlueShip();
		void goToGreenShip();
		void goToCurrentDestination();

		void thereAndBackAgain();
		void backwardUntilBlackLine();

		// Sanity check stuff
		void testMoviments();
		void testClaw();
		void testColorSensor();
		void testDistanceSensor();

};

#endif  // ROBOT_HPP