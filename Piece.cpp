//Functions definitions
#include "Piece.h"

//Constructor
Piece::Piece(int x, int y, char colour) {
    this->x = x;
    this->y = y;
    this->colour = colour;
    pieceType = 0;
}

// get functions (x position, y position, colour, and piece type)
int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}

char Piece::getColour() {
    return colour;
}

char Piece::getPieceType() {
    return pieceType;
}

//set function for position
void Piece::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}