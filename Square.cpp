#include "Square.h"

Square::Square() {
}

Square::Square(int piece) {
    x = 0;
    y = 0;
    switch (piece) {
    case 1:
        this->currentPiece = new Pawn{x, y, 'w'};
        break;
    case -1:
        this->currentPiece = new Pawn{x, y, 'b'};
        break;
    case 2:
        this->currentPiece = new Rook{x, y, 'w'};
        break;
    case -2:
        this->currentPiece = new Rook{x, y, 'b'};
        break;
    case 3:
        this->currentPiece = new Bishop{x, y, 'w'};
        break;
    case -3:
        this->currentPiece = new Bishop{x, y, 'b'};
        break;
    case 4:
        this->currentPiece = new Knight{x, y, 'w'};
        break;
    case -4:
        this->currentPiece = new Knight{x, y, 'b'};
        break;
    case 5:
        this->currentPiece = new King{x, y, 'w'};
        break;
    case -5:
        this->currentPiece = new King{x, y, 'b'};
        break;
    case 6:
        this->currentPiece = new Queen{x, y, 'w'};
        break;
    case -6:
        this->currentPiece = new Queen{x, y, 'b'};
        break;
    default:
        break;
    }
}

Piece *Square::getPiece() {
    return currentPiece;
}

int Square::getXPosition() {
    return x;
}

int Square::getYPosition() {
    return y;
}

void Square::setPiece(int newPiece) {
    switch (newPiece) {
    case 1:
        this->currentPiece = new Pawn{x, y, 'w'};
        break;
    case -1:
        this->currentPiece = new Pawn{x, y, 'b'};
        break;
    case 2:
        this->currentPiece = new Rook{x, y, 'w'};
        break;
    case -2:
        this->currentPiece = new Rook{x, y, 'b'};
        break;
    case 3:
        this->currentPiece = new Bishop{x, y, 'w'};
        break;
    case -3:
        this->currentPiece = new Bishop{x, y, 'b'};
        break;
    case 4:
        this->currentPiece = new Knight{x, y, 'w'};
        break;
    case -4:
        this->currentPiece = new Knight{x, y, 'b'};
        break;
    case 5:
        this->currentPiece = new King{x, y, 'w'};
        break;
    case -5:
        this->currentPiece = new King{x, y, 'b'};
        break;
    case 6:
        this->currentPiece = new Queen{x, y, 'w'};
        break;
    case -6:
        this->currentPiece = new Queen{x, y, 'b'};
        break;
    default:
        break;
    }
}

void Square::setXPosition(int x) {
    this->x = x;
}

void Square::setYPosition(int y) {
    this->y = y;
}
