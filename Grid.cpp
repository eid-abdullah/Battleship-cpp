
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
    if((cells[row][col]=='X') ||(cells[row][col]=='S')){
        return true;
    }
    return false;
}
bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) return false;

    if (horizontal) {
        if (col + shipSize - 1 >= 10) return false;

        for (int i = col; i < col + shipSize; i++) {
            if (isTileOccupied(row, i)) return false;
        }
        return true;
    } else {
        if (row + shipSize - 1 >= 10) return false;

        for (int i = row; i < row + shipSize; i++) {
            if (isTileOccupied(i, col)) return false;
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
    cells[row][col]== 'X';
}
void Grid::markMiss(int row, int col){
    cells[row][col]== 'M';
}

