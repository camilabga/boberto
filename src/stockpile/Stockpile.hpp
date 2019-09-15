#ifndef STOCK_HPP
#define STOCK_HPP

#include <Arduino.h>

#define MAX_H 5

struct PILE {
int index;
uint8_t height;
};

enum SHIP {
    blueShip,
    greenShip
};

class Stockpile {
    private:
        // representation of the ships
        int greenIndex = 0;
        int blueIndex = 0;
        uint8_t greenHeight[MAX_H];
        uint8_t blueHeight[MAX_H];

        
        // variable representation of te actual state of the ships
        PILE pile;

        // fill the ships with empty values
        void emptyPiles();
        
    public:
        Stockpile();
        ~Stockpile();

        // update the index and height of a container pile int the rigth ship
        void updateStockpile(SHIP color);

        // recover the next position where to put the contaienr in color passed ship
        PILE getStockpile(SHIP);

};

#endif  // STOCK_HPP