#include "HumanPlayer.h"
#include <iostream>
#include <limits>

HumanPlayer::HumanPlayer(const char* name) : Player(name) {}

bool HumanPlayer::readPlacementInput(int& row, int& col, bool& horizontal) {
    char dir;

    std::cout << "Enter row (0-9): ";
    if (!(std::cin >> row)) return false;

    std::cout << "Enter col (0-9): ";
    if (!(std::cin >> col)) return false;

    std::cout << "Enter direction (H/V): ";
    if (!(std::cin >> dir)) return false;

    if (dir == 'H' || dir == 'h') horizontal = true;
    else if (dir == 'V' || dir == 'v') horizontal = false;
    else return false;

    return true;
}

bool HumanPlayer::readMoveInput(int& row, int& col) {
    std::cout << "Attack row (0-9): ";
    if (!(std::cin >> row)) return false;

    std::cout << "Attack col (0-9): ";
    if (!(std::cin >> col)) return false;

    return true;
}

void HumanPlayer::placeAllShips() {
    const char symbols[5] = { 'C', 'B', 'R', 'U', 'D' };

    for (int i = 0; i < 5; i++) {
        int shipSize = ships[i]->getSize();
        int row, col;
        bool horizontal;

        while (true) {
            std::cout << "\nPlacing " << ships[i]->getName()
                    << " (size = " << shipSize << ")\n";

            if (!readPlacementInput(row, col, horizontal)) {
                std::cout << "Invalid input. Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // Validate bounds + overlap using Grid::inBounds (you already check '~' there)
            if (!grid.inBounds(row, col, shipSize, horizontal)) {
                std::cout << "Invalid placement (out of bounds or overlap). Try again.\n";
                continue;
            }

            grid.placeShip(row, col, shipSize, horizontal, symbols[i]);

            // Optional: show grid after each placement (nice for user)
            displayMyGrid();

            break;
        }
    }
}

void HumanPlayer::makeMove(Player* opponent) {
    int row, col;

    while (true) {
        if (!readMoveInput(row, col)) {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Basic bounds check
        if (row < 0 || row > 9 || col < 0 || col > 9) {
            std::cout << "Out of bounds. Try again.\n";
            continue;
        }

        // Don't allow shooting same tile twice
        if (wasTileAlreadyAttacked(opponent, row, col)) {
            std::cout << "You already attacked this tile. Try again.\n";
            continue;
        }

        processAttack(opponent, row, col);

        // Requirement: print both boards after each move
        std::cout << "\n=== Boards after Human move ===\n";
        this->displayMyGrid();
        opponent->displayOpponentGrid();

        break;
    }
}
