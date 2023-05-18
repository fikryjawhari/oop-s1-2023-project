#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include <vector>

class Board {
private:
    Square *squareArray;

public:
    Board();
    Board(char puzzle);
    Square *getSquareArray();
    // bool validMove(Move move);
};

#endif // BOARD_H
