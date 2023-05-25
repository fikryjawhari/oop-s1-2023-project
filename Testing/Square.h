// Defining square
#ifndef SQUARE_H
#define SQUARE_H

// Including pieces
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Square.h"

// Declaring class and variables
class Square {
private:
    int x;
    int y;
    Piece *currentPiece;

public:
    // constructors
    Square();
    Square(int piece);
    // Getters
    Piece *getPiece();
    char getPieceName();
    int getXPosition();
    int getYPosition();
    // Setters
    void setPiece(int piece);
    void setPiecePtr(Piece *piece);
    void setXPosition(int x);
    void setYPosition(int y);
    // Destructor
    ~Square();
};

#endif // SQUARE_H
