#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include <iostream>
#include <vector>

class Board {
private:
    Square *squareArray;

public:
    Board();
    Square *getSquareArray();
    bool validMove(Move move);
    ~Board();
};

#endif // BOARD_H
