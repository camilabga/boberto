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

		// Sensores Frontais
		Sensor sensorFL, sensorFR;
		// Sensores Frontais mais externos
		Sensor sensorFLL, sensorFRR;
		// Sensores Traseiros
		Sensor sensorBL, sensorBR;
		// Sensores Laterais
		Sensor sensorSB, sensorSF;

		DistanceSensor lidar;

		ColorSensor colorSensor{32};

	public:
		Robot();
		~Robot();

		void begin();

		void stop();

		void forward(uint32_t goal = 0, int16_t vel = 255);

		void backward(uint32_t goal = 0, int16_t vel = 255);

		void sidewaysRight(uint32_t goal = 0, int16_t vel = 255);
		// void sidewaysRight();

		void sidewaysLeft(uint32_t goal = 0, int16_t vel = 255);
		// void sidewaysLeft();

		void rotateLeft(uint32_t goal = 0, int16_t vel = 255);
		// void rotateLeft();

		void rotateRight(uint32_t goal = 0, int16_t vel = 255);
		// void rotateRight();

		void moveRightForward(uint32_t goal = 0, int16_t vel = 255);
		// void moveRightForward();

		void moveRightBackward(uint32_t goal = 0, int16_t vel = 255);
		// void moveRightBackward();

		void moveLeftForward(uint32_t goal = 0, int16_t vel = 255);
		// void moveLeftForward();

		void moveLeftBackward(uint32_t goal = 0, int16_t vel = 255);
		// void moveLeftBackward();

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