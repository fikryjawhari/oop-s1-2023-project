#ifndef BOARD_H
#define BOARD_H

#include "Row.h"

class Board {
private:
    Row *rowArray;

public:
    Board();
    /* i think we need a game class, where the load next state
    and reset game and stuff happens, cause it doesnt super
    make sense to have that in board, this should just be
    a class that stores the board and nothing else, basically
    just a record of the pieces, whereas the game class can do
    all the heavy lifting */
};

#endif // BOARD_H
