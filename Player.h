#pragma once

#include "Ship.h"
#include "Grid.h"

#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"

class Player{
    protected:
    char* playerName;
    Ship* ships[5];
    Grid grid;

    int symbolToShipIndex(char symbol) const;

    void processAttack(Player* opponent, int row, int col);


public:
    Player(const char* name);
    virtual ~Player();

    virtual void placeAllShips() = 0;          
    virtual void makeMove(Player* opponent) = 0;

    bool allShipsSunk() const;

    void displayMyGrid() const;                
    void displayOpponentGrid() const;    
    
    bool wasTileAlreadyAttacked(const Player* opponent, int row, int col) const;

};