// Defining board
#ifndef BOARD_H
#define BOARD_H

// Square includes all additional files needed by board
#include "Square.h"

// Declaring class including data members and methods
class Board {
private:
    Square *squareArray;

public:
    Board();                  // Constructor
    Square *getSquareArray(); // Getter
    // Board wide move validation
    bool takeValidation(Move move);
    bool validMove(Move move);
    void movePiece(Move move);
    // Copy functions for pointer issues
    void copySquareArray(Square *squareArrayToCopy);
    void setSquareArray(Square *squareArray);
};

#endif // BOARD_H
