#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"

class Square {
private:
    int xPosition;
    int yPosition;
    Piece *currentPiece;

public:
    Square();
    Square(Piece *newPiece);

    Piece *getPiece();
    int getXPosition();
    int getYPosition();

    void setPiece(Piece *newPiece);
    void setXPosition(int xPosition);
    void setYPosition(int yPosition);
};

#endif // SQUARE_H
