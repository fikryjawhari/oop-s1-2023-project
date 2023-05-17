#ifndef BOARD_H
#define BOARD_H

#include "Square.h"

class Board {
private:
    Square *squareArray;

public:
    Board();
    Square *getSquareArray();
    bool validMove(int x, int y, int newX, int newY);
};

#endif // BOARD_H
