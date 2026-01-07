#include "Ship.h"
#include "Grid.h"
class Player{
    private :
        char* playerName;
        Ship* ships[5];
        Grid grid;
    public :
        Player(const char* name);
        virtual ~Player();
        virtual void placeAllShips();
        virtual void makeMove(Player* opponent);
        bool allShipsSunk() const;
        void displayGrid();
};