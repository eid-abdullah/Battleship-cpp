
#include "Grid.h"

Grid :: Grid(){
    int i, j;
    for(i=0 ; i < 10; i++ ){
        for(j=0 ; j < 10 ; j++){
            cells[i][j] = '~';
        }
    }
}

bool Grid::isTileOccupied(int row, int col) const{
    return cells[row][col] != '~';
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) return false;

    if (horizontal) {
        if (col + shipSize > 10) return false;

        for (int c = col; c < col + shipSize; c++) {
            if (cells[row][c] != '~') return false;
        }
        return true;

    } else {
        if (row + shipSize > 10) return false;

        for (int i = row; i < row + shipSize; i++) {
            if (cells[i][col] != '~') return false;
        }
        return true;
    }
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol) {
    if (horizontal) {
        for (int i = col; i < col + shipSize; i++) {
            cells[row][i] = symbol;
        }
    } else {
        for (int i = row; i < row + shipSize; i++) {
            cells[i][col] = symbol;
        }
    }
}
void Grid::markHit(int row, int col){
    cells[row][col] = 'X';
}
void Grid::markMiss(int row, int col){
    cells[row][col] = 'M';
}


char Grid::getCell(int row, int col) const {
    return cells[row][col];
}

void Grid::printGrid(bool hideShips) const {

    std::cout << "  ";
    for (int c = 0; c < 10; c++) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    for (int r = 0; r < 10; r++) {
        std::cout << r << " ";
        for (int c = 0; c < 10; c++) {
            char cell = cells[r][c];
            if (hideShips && cell != '~' && cell != 'X' && cell != 'M') {
                std::cout << "~ ";
            } else {
                std::cout << cell << " ";
            }
        }
        std::cout << "\n";
    }

}

