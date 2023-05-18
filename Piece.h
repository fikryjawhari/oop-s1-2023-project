#ifndef PIECE_H
#define PIECE_H

using namespace std;

#include "Move.h"

class Piece {
protected:
    char colour;
    int x;
    int y;

public:
    virtual bool validMove() = 0;
    Piece();
    Piece(int x, int y, char colour);
    int getX();
    int getY();
};

#endif // PIECE_H
