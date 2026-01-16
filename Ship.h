#pragma once
class Ship {

    private :
        char* name ;
        int size;
        int hitsTaken;

    public :
        Ship(const char* shipName , int shipSize);
        virtual ~Ship() ;

        virtual void takeHit();
        bool isSunk() const;

        int getSize() const;
        const char* getName() const;
};