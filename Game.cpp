#include "Game.h"
#include <iostream>

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

void Game::setup() {
    std::cout << "=== Player 1 placing ships ===" << std::endl;
    player1->placeAllShips();

    std::cout << "\n=== Player 2 placing ships ===" << std::endl;
    player2->placeAllShips();
}

bool Game::isGameOver() const {
    return player1->allShipsSunk() || player2->allShipsSunk();
}

void Game::start() {
    while (!isGameOver()) {
        std::cout << "\n=== Player 1 turn ===" << std::endl;
        player1->makeMove(player2);
        if (player2->allShipsSunk()) {
            std::cout << "\nPlayer 1 wins!" << std::endl;
            return;
        }

        std::cout << "\n=== Player 2 turn ===" << std::endl;
        player2->makeMove(player1);
        if (player1->allShipsSunk()) {
            std::cout << "\nPlayer 2 wins!" << std::endl;
            return;
        }
    }

}