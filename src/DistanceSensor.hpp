#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <Arduino.h>
#include "VL53L0X.h"

class DistanceSensor {
    private:
        VL53L0X sensor;
    
    public:
        DistanceSensor();
        ~DistanceSensor();
        
        void begin();

        int getDistance();
        bool getContainerGap(); 
};

#endif // DISTANCESENSOR_H