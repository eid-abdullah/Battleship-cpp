#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const char* name);

    void placeAllShips() override;
    void makeMove(Player* opponent) override;

private:
    bool readPlacementInput(int& row, int& col, bool& horizontal);
    bool readMoveInput(int& row, int& col);
};
