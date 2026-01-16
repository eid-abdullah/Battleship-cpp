#include "Player.h"
#include <cstring>
#include <iostream>

Player::Player(const char* name) {
    // copy player name
    playerName = new char[std::strlen(name) + 1];
    std::strcpy(playerName, name);

    // [0]- Carrier, [1]- Battleship, [2]- Cruiser, [3]- Submarine, [4]- Destroyer
    ships[0] = new Carrier();      
    ships[1] = new Battleship();   
    ships[2] = new Cruiser();      
    ships[3] = new Submarine();    
    ships[4] = new Destroyer();    
}

Player::~Player() {
    delete[] playerName;

    for (int i = 0; i < 5; i++) {
        delete ships[i];
    }
}

bool Player::allShipsSunk() const {
    for (int i = 0; i < 5; i++) {
        if (!ships[i]->isSunk())
            return false;
    }
    return true;
}

int Player::symbolToShipIndex(char symbol) const {
    // C Carrier, B Battleship, R Cruiser, U Submarine, D Destroyer
    if (symbol == 'C') return 0;
    if (symbol == 'B') return 1;
    if (symbol == 'R') return 2;
    if (symbol == 'U') return 3;
    if (symbol == 'D') return 4;
    return -1;
}

void Player::processAttack(Player* opponent, int row, int col) {
    char cell = opponent->grid.getCell(row, col);

    // Already attacked?
    if (cell == 'X' || cell == 'M') {
        std::cout << "Already attacked this tile. Try again.\n";
        return;
    }

    // Miss
    if (cell == '~') {
        opponent->grid.markMiss(row, col);
        std::cout << "Miss!\n";
        return;
    }

    int idx = symbolToShipIndex(cell);
    if (idx != -1) {
        opponent->ships[idx]->takeHit();
        opponent->grid.markHit(row, col);
        return;
    }

    // Fallback 
    opponent->grid.markMiss(row, col);
}

void Player::displayMyGrid() const {
    std::cout << "\n--- " << playerName << " (My Grid) ---\n";
    grid.printGrid(false);
}

void Player::displayOpponentGrid() const {
    std::cout << "\n--- " << playerName << " (Opponent View) ---\n";
    grid.printGrid(true);
}

bool Player::wasTileAlreadyAttacked(const Player* opponent, int row, int col) const {
    char cell = opponent->grid.getCell(row, col);
    return (cell == 'X' || cell == 'M');
}

