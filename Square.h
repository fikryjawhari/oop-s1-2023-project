#ifndef SQUARE_H
#define SQUARE_H

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Square.h"

class Square {
private:
    int x;
    int y;
    Piece *currentPiece;

public:
    Square();
    Square(int piece);

    Piece *getPiece();
    char getPieceName();
    int getXPosition();
    int getYPosition();

    void setPiece(int piece);
    void setPiecePtr(Piece *piece);
    void setXPosition(int x);
    void setYPosition(int y);
};

#endif // SQUARE_H
