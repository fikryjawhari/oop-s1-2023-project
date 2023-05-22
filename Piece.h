//Defining abstract piece
#ifndef PIECE_H
#define PIECE_H

using namespace std;

#include "Move.h"

//Declaring class and functions
class Piece {
protected:
    char colour;
    char pieceType;
    int x;
    int y;

public:
    virtual bool validMove(int newX, int newY) = 0; //polymorphic function for inheritance
    Piece(int x, int y, char colour); //constructor
    //Getters and setters
    int getX(); 
    int getY();
    char getColour();
    char getPieceType();
    void setPosition(int x, int y);
};

#endif // PIECE_H
