#include "AiPlayer.h"
#include <iostream>
#include <cstdlib> // rand

AiPlayer::AiPlayer(const char* name) : Player(name) {}

int AiPlayer::getRandomCoordinate() const {
    return std::rand() % 10;
}

void AiPlayer::placeAllShips() {
    const char symbols[5] = { 'C', 'B', 'R', 'U', 'D' };

    for (int i = 0; i < 5; i++) {
        int shipSize = ships[i]->getSize();

        while (true) {
            int row = getRandomCoordinate();
            int col = getRandomCoordinate();
            bool horizontal = (std::rand() % 2 == 0);

            if (grid.inBounds(row, col, shipSize, horizontal)) {
                grid.placeShip(row, col, shipSize, horizontal, symbols[i]);
                break;
            }
        }
    }
}

void AiPlayer::makeMove(Player* opponent) {
    while (true) {
        int row = getRandomCoordinate();
        int col = getRandomCoordinate();

        if (wasTileAlreadyAttacked(opponent, row, col))
            continue;

        processAttack(opponent, row, col);

        std::cout << "\n=== Boards after AI move ===\n";
        this->displayMyGrid();
        opponent->displayOpponentGrid();
        break;
    }
}
