#ifndef PIECE_H
#define PIECE_H

using namespace std;

#include "Move.h"

class Piece {
protected:
    char colour;
    char pieceType;
    int x;
    int y;

public:
    virtual bool validMove(int newX, int newY) = 0;
    Piece(int x, int y, char colour);
    int getX();
    int getY();
    char getColour();
    char getPieceType();
    void setPosition(int x, int y);
};

#endif // PIECE_H
