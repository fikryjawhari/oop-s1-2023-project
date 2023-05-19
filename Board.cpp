#include "Board.h"
#include "Piece.h"

Board::Board() {
    squareArray = new Square[8 * 8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squareArray[i * 8 + j].setXPosition(j + 1);
            squareArray[i * 8 + j].setYPosition(8 - i);
        }
    }
}

Square *Board::getSquareArray() {
    return squareArray;
}
// squareArray[(8 - (move.y))*8 + (move.x)]
bool Board::validMove(Move move) {
    Piece *currentPiece = squareArray[move.x * 8 + move.y].getPiece();
    bool pieceValidMove = currentPiece->validMove(move.newX, move.newY);
    if (pieceValidMove == true) {
        // This is a fucking huge function, need to implement
        // 1) piece moving logic and 2) along the piece path, is it
        // empty for each piece
        if (currentPiece != nullptr) { // if current piece is actually a piece
            char currentPieceType = currentPiece->getPieceType();
            switch (currentPieceType) {
            case 'P': // IMPLEMENTED
                if (currentPiece->getColour() == 'w') {
                    if (move.x != move.newX) { // trying to move diagonally
                        while (move.y != move.newY) {
                            if (squareArray[(8 - (move.y + 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
                                if (squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'b') {                   // if piece diagonal is black, can take
                                    move.y++;                                                                                  // this should end loop, cause diagonal move means newY is only 1 bigger
                                } else {                                                                                       // if piece diagonal is white, obviously cant move
                                    return false;
                                }
                            } else // if diagonal square is empty, obviously cant make that move (not implementing en passant)
                                return false;
                        }
                    } else if (move.x == move.newX) { // trying to move straight
                        while (move.y != move.newY) {
                            if (squareArray[(8 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead if empty
                                move.y++;
                            } else {
                                return false;
                            }
                        }
                    }
                } else if (currentPiece->getColour() == 'b') {
                    if (move.x != move.newX) { // trying to move diagonally
                        while (move.y != move.newY) {
                            if (squareArray[(8 - (move.y - 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
                                if (squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'w') {                   // if piece diagonal is black, can take
                                    move.y--;                                                                                  // this should end loop, cause diagonal move means newY is only 1 bigger
                                } else {                                                                                       // if piece diagonal is white, obviously cant move
                                    return false;
                                }
                            } else // if diagonal square is empty, obviously cant make that move (not implementing en passant)
                                return false;
                        }
                    } else if (move.x == move.newX) { // trying to move straight
                        while (move.y != move.newY) {
                            if (squareArray[(8 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead if empty
                                move.y--;
                            } else {
                                return false;
                            }
                        }
                    }
                }
                break;
            case 'R':
                break;
            case 'B':
                break;
            case 'N':
                break;
            case 'K':
                break;
            case 'Q':
                break;
            }
        } else {
            cout << "Empty square, no move to make\n";
            return false;
        }
    } else {
        cout << "Piece valid move false\n";
        return false;
    }
}

Board::~Board() {
    delete[] squareArray;
}
