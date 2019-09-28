#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>

#include "sensors/Sensor.hpp"
#include "sensors/colorSensor/ColorSensor.hpp"
#include "sensors/distanceSensor/DistanceSensor.hpp"

#include "actuators/motor/Motor.hpp"
#include "actuators/claw/Claw.hpp"

class Robot {
    private:
        Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};
        Claw claw{26, 27, 28, 29, 30};

        Sensor sensorFL, sensorFR, sensorBL, sensorBR;
        DistanceSensor lidar;
        ColorSensor colorSensor{2};

    public:
        Robot();
        ~Robot();

        void stop();
        void forward(unsigned long int goal);
        // void forward(unsigned char vel);
        void forward();

        void begin();

        void backward(unsigned long int goal);
        // void backward(unsigned char vel);
        void backward();

        void sidewaysRight(unsigned long int goal);
        // void sidewaysRight(unsigned char vel);
        void sidewaysRight();

        void sidewaysLeft(unsigned long int goal);
        // void sidewaysLeft(unsigned char vel);
        void sidewaysLeft();

        void rotateLeft(unsigned long int goal);
        // void rotateLeft(unsigned char vel);
        void rotateLeft();

        void rotateRight(unsigned long int goal);
        // void rotateRight(unsigned char vel);
        void rotateRight();

        void moveRightForward(unsigned long int goal);
        void moveRightBackward(unsigned long int goal);
        void moveLeftForward(unsigned long int goal);
        void moveLeftBackward(unsigned long int goal);

        // Movimentação da garra
        void catchContainer(uint8_t container);
        void releaseContainer(uint8_t container);

        void findBlackLine();
        void alignBetweenContainers();
        void followLineUntilGap();

        // Sensor de cor
        void calibrateColorSensor();

        // Sanity check stuff
        void testMoviments();
        void testClaw();
        void testColorSensor();
};

#endif  // ROBOT_HPP