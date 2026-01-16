#include <iostream>
#include <cstring> 
#include "Ship.h"
Ship::Ship(const char* shipName , int shipSize){
    size = shipSize;
    hitsTaken = 0;

    name = new char[strlen(shipName) +1];
    strcpy(name , shipName);
}
Ship::~Ship() {
    delete[] name;
}
bool Ship::isSunk() const {
    return hitsTaken >= size;
}

void Ship::takeHit() {
    hitsTaken++;
    std::cout << name << " got hit!" << std::endl;

    if (isSunk()) {
        std::cout << name << " sunk!" << std::endl;
    }
}


int Ship::getSize() const {
    return size;
}

const char* Ship::getName() const {
    return name;
}


