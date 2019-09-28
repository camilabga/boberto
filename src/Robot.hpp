#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>

#include "Claw.hpp"
#include "ColorSensor.hpp"
#include "DistanceSensor.hpp"
#include "Motor.hpp"
#include "LineSensor.hpp"

struct Ship {
	uint8_t currentPile = 0;
	uint8_t currentHeight = 0;

	void increment () {
		currentHeight++;
		if (currentHeight == 5) {
			currentPile = 1;
			currentHeight = 0;
		}
	}
};

enum CONTAINER_SIDE {
	clawSide = 1,
	otherSide = 0
};

struct ContainerZone {
	uint8_t clawSide[2] = {4,4};
	uint8_t otherSide[2] = {4,4};

	bool isEmpty(uint8_t side) {
		if (side) {
			if (clawSide[1] == 0) return true;
			else return false;
		} else {
			if (otherSide[1] == 0) return true;
			else return false;
		}
	}

	uint8_t getHeight(uint8_t side) {
		if (side) {
			if (clawSide[0] == 0) return clawSide[1];
			return clawSide[0];
		} else {
			if (otherSide[0] == 0) return otherSide[1];
			return otherSide[0];
		}
	}

	void updateHeight(uint8_t side) {
		if (side) {
			if (clawSide[0] == 0) {
				clawSide[1]--;
			} else {
				clawSide[0]--;
			}
		} else {
			if (otherSide[0] == 0) {
				otherSide[1]--;
			} else {
				otherSide[0]--;
			}
		}
	}


};

/*
	side: true ==> green | blue
		  false ==> blue | green
*/

struct Arena {
	ContainerZone containers[3];
	Ship greenShip;
	Ship blueShip;
	bool side = true;
};


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
		LineSensor blueSensorL, blueSensorR;

		DistanceSensor lidar;

		ColorSensor colorSensor{32};

		Arena arena;
		uint8_t currentZone = 1;

		COLOR currentDestination = None;

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
		void catchContainer();

		//void releaseContainer(uint8_t container);
		void releaseContainer(COLOR color);

		void findBlackLine();
		void findBlueLine();

		void alignBetweenContainers(uint8_t zone);
		void alignWithShip();

		void followLineUntilGap();
		void followHorizontalRight();
		void followHorizontalLeft();
		
		void backwardUntilBlackLine();

		void goToContainerZone(uint8_t zone);

		void goToBlueShip();
		void goToGreenShip();
		void goToCurrentDestination();

		// Sensor de cor
		void calibrateColorSensor();
		void chooseContainerDestination();

		// Sanity check stuff
		void testMoviments();
		void testClaw();
		void testColorSensor();
		void testDistanceSensor();
};

#endif  // ROBOT_HPP