#ifndef DISTANCESENSOR_HPP
#define DISTANCESENSOR_HPP

#include <Arduino.h>
#include "VL53L0X.h"

class DistanceSensor {
    private:
        VL53L0X sensor;
    
    public:
        DistanceSensor();
        ~DistanceSensor();
        
        // Inicializador do sensor 
        void begin();

        // Realiza uma leitura
        int getDistance();
        // Detecta uma mudança brusca nos valores lidos
        bool getContainerGap(); 
};

#endif // DISTANCESENSOR_HPP