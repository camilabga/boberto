#include "DistanceSensor.hpp"

DistanceSensor::DistanceSensor() {}

DistanceSensor::~DistanceSensor() {}

/*
    Não colocar no construtor da classe e chamar  
    no setup para o inferno não ascender a terra
*/
void DistanceSensor::begin() {
    sensor.init();
    sensor.setTimeout(700);
    // sensor.startContinuous();
}

uint16_t DistanceSensor::getDistance() {
    //return sensor.readRangeContinuousMillimeters();
    return sensor.readRangeSingleMillimeters();
}

bool DistanceSensor::getContainerGap() {
    uint16_t distance = sensor.readRangeContinuousMillimeters();
    
    if(distance >= 90) 
        return true;
    else
        return false;
}