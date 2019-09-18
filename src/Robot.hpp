#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>

#include "Claw.hpp"
#include "ColorSensor.hpp"
#include "DistanceSensor.hpp"
#include "Motor.hpp"
#include "LineSensor.hpp"

class Robot {
	private:
		Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};
		
		Claw claw{26, 27, 28, 29, 30};

		// Sensores Frontais
		LineSensor sensorFL, sensorFR;
		// Sensores Frontais mais externos
		LineSensor sensorFLL, sensorFRR;
		// Sensores Traseiros
		LineSensor sensorBL, sensorBR;
		// Sensores Laterais
		LineSensor sensorSB, sensorSF;

		DistanceSensor lidar;

		ColorSensor colorSensor{32};

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