#include "Motor.hpp"

// Instanciando os singletons
Motor* Motor::instance0;
Motor* Motor::instance1;
Motor* Motor::instance2;
Motor* Motor::instance3;

void Motor::isr0() { instance0->handleInterrupt(); }

void Motor::isr1() { instance1->handleInterrupt(); }

void Motor::isr2() { instance2->handleInterrupt(); }

void Motor::isr3() { instance3->handleInterrupt(); }

void Motor::handleInterrupt() {
    cont++;

    if (cont == goal) {
        cont = 0;
        goal = 0;

        analogWrite(pin1, 0);
        analogWrite(pin2, 0);
        
		finished = false;
    }
}

Motor::Motor(uint8_t _whichISR) : whichISR(_whichISR), cont(0) {}

Motor::~Motor() {}

void Motor::begin() {
    if (whichISR == 0) {
        instance0 = this;

        attachInterrupt(
			digitalPinToInterrupt(encoderPin), 
			isr0, 
			RISING
		);

    } else if (whichISR == 1) {
        instance1 = this;

        attachInterrupt(
			digitalPinToInterrupt(encoderPin), 
			isr1, 
			RISING
		);

    } else if (whichISR == 2) {
        instance2 = this;

        attachInterrupt(
			digitalPinToInterrupt(encoderPin), 
			isr2, 
			RISING
		);

    } else if (whichISR == 3) {
        instance3 = this;

        attachInterrupt(
			digitalPinToInterrupt(encoderPin), 
			isr3, 
			RISING
		);
    }
}

void Motor::setPins(uint8_t _encoderPin, uint8_t _pin1, uint8_t _pin2) {
    encoderPin = _encoderPin;
    pin1 = _pin1;
    pin2 = _pin2;

    pinMode(encoderPin, INPUT_PULLUP);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::forward(uint32_t _goal, int16_t vel) {
    if (_goal != 0) {
        cont = 0;
        goal = _goal;
        finished = true;
    }

    if (vel > 0) {
        analogWrite(pin1, vel);
        analogWrite(pin2, 0);
    } else {
        analogWrite(pin1, 0);
        analogWrite(pin2, vel);
    }
}

void Motor::backward(uint32_t _goal, int16_t vel) {
    if (_goal != 0) {
        cont = 0;
        goal = _goal;
        finished = true;
    }
	
    if (vel > 0) {
        analogWrite(pin1, 0);
        analogWrite(pin2, vel);
    } else {
        analogWrite(pin1, vel);
        analogWrite(pin2, 0);
    }
}

void Motor::stop() {
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
}

bool Motor::getFinished() { return finished; }