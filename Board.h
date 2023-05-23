#ifndef BOARD_H
#define BOARD_H

#include "Square.h"

class Board {
private:
    Square *squareArray;

public:
    Board();
    Square *getSquareArray();
    bool takeValidation(Move move);
    bool validMove(Move move);
    void movePiece(Move move);
    void copySquareArray(Square *squareArrayToCopy);
    void setSquareArray(Square *squareArray);
    // ~Board();
};

#endif // BOARD_H
