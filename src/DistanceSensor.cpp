#include "DistanceSensor.hpp"

DistanceSensor::DistanceSensor() {
    // sensor = Adafruit_VL53L0X();
}

DistanceSensor::~DistanceSensor() {}

/*
    Não colocar no construtor da classe e chamar  
    no setup para o inferno não ascender a terra
*/
void DistanceSensor::begin() {
    // Serial.println("Going to init");
    delay(100);
    sensor.init();
    sensor.setTimeout(500);
    delay(100);
    // Serial.println("Initialized");
    // sensor.startContinuous();
}

uint16_t DistanceSensor::getDistance() {
    //return sensor.readRangeContinuousMillimeters();

    Serial.print(" Class: ");
    Serial.println(sensor.readRangeSingleMillimeters());
   
    uint16_t messurement = sensor.readRangeSingleMillimeters();
   
    return messurement;
    /*
    VL53L0X_RangingMeasurementData_t measure;
    sensor.rangingTest(&measure, false);

    // phase failures have incorrect data
    if (measure.RangeStatus != 4) {  
        Serial.print("Distance (mm): "); 
        Serial.println(measure.RangeMilliMeter);
    } else {
        Serial.println(" out of range ");
    }

    return 0;
    */
}

bool DistanceSensor::getContainerGap() {
    /*
    uint16_t distance = sensor.readRangeContinuousMillimeters();

    if(distance >= 90) 
        return true;
    else
        return false;
    */
   return false;
}