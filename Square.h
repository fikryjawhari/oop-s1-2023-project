#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"

class Square {
private:
    int x;
    int y;
    Piece *currentPiece;

public:
    Square();
    Square(Piece *newPiece);

    Piece *getPiece();
    int getXPosition();
    int getYPosition();

    void setPiece(Piece *newPiece);
    void setXPosition(int x);
    void setYPosition(int y);
};

#endif // SQUARE_H
