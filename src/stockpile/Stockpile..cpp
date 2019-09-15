#include "Stockpile.hpp"

Stockpile::~Stockpile() {}

Stockpile::Stockpile() {
    emptyPiles();
}

void Stockpile::emptyPiles() {
    memset(blueHeight,0,sizeof(uint8_t));
    memset(greenHeight,0,sizeof(uint8_t));
}

void Stockpile::updateStockpile(SHIP color){
    if(color == greenShip) {
        if(greenHeight[greenIndex] >= MAX_H){
            greenIndex += 1;
        }
        greenHeight[greenIndex] = greenHeight[greenIndex] + 1;
        
    } else {
       if(blueHeight[blueIndex] >= MAX_H){
            blueIndex += 1;
        }
        blueHeight[blueIndex] = blueHeight[blueIndex] + 1;
    }
}

PILE Stockpile::getStockpile(SHIP color) {
    if(color == greenShip){
        pile.index = 0;
        pile.height = 1;
    } else {
        pile.index = 1;
        pile.height = 0;
}

return pile;
}
