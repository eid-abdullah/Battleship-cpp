#pragma once
#include "Player.h"

class AiPlayer : public Player {
public:
    AiPlayer(const char* name);

    void placeAllShips() override;
    void makeMove(Player* opponent) override;

private:
    int getRandomCoordinate() const;
};
