#include "DistanceSensor.hpp"

DistanceSensor::DistanceSensor() {}

DistanceSensor::~DistanceSensor() {}

/*
    Não colocar no construtor da classe e chamar  
    no setup para o inferno não ascender a terra
*/
void DistanceSensor::begin() {
    sensor.init();
    sensor.setTimeout(500);
    sensor.startContinuous();
}

int DistanceSensor::getDistance() {
    // -55 para compensar o erro
    return sensor.readRangeContinuousMillimeters() - 55;
}

bool DistanceSensor::getContainerGap() {
    int distance = sensor.readRangeContinuousMillimeters();
    distance -= 55;

    if(distance > 50) 
        return true;
    else
        return false;
}