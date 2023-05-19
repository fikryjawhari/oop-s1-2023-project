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

bool Board::validMove(Move move) {
    Piece *currentPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    if (currentPiece != nullptr) {
        bool pieceValidMove = currentPiece->validMove(move.newX + 1, move.newY + 1);
        if (pieceValidMove == true) {
            cout << "Piece valid move\n";
            if (currentPiece != nullptr) { // if current piece is actually a piece
                char currentPieceType = currentPiece->getPieceType();
                switch (currentPieceType) {
                case 'P': // IMPLEMENTED
                    if (currentPiece->getColour() == 'w') {
                        if (move.x != move.newX) { // trying to move diagonally
                            while (move.y != move.newY) {
                                if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
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
                                if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead if empty
                                    move.y++;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else if (currentPiece->getColour() == 'b') {
                        if (move.x != move.newX) { // trying to move diagonally
                            while (move.y != move.newY) {
                                if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
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
                                if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead if empty
                                    move.y--;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                    return true;
                    break;
                case 'R':
                    // either moves across or up/down, check path is clear in chosen direction
                    if (move.x == move.newX) {        // moving up/down
                        while (move.y != move.newY) { // while not at end location
                            if (move.newY > move.y) { // moving up
                                if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                    move.y++;
                                } else {
                                    return false; // square is occupied
                                }
                            } else if (move.newY < move.y) { // moving down
                                if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                    move.y--;
                                } else {
                                    return false; // square is occupied
                                }
                            }
                        }
                    } else if (move.y == move.newY) { // moving left/right
                        while (move.x != move.newX) { // while not at end location
                            if (move.newX > move.x) { // moving right
                                if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                    move.x++;
                                } else {
                                    return false; // square is occupied
                                }
                            } else if (move.newX < move.x) { // moving left
                                if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                    move.x--;
                                } else {
                                    return false; // square is occupied
                                }
                            }
                        }
                    }
                    if (squareArray[move.newX * 8 + move.newY].getPiece() != nullptr) { // if last square is not empty
                        if (currentPiece->getColour() == 'w' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'b') {
                            return true;
                        } else if (currentPiece->getColour() == 'b' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'w') {
                            return true; // return true if opposite colour
                        } else {         // return false if same colour
                            return false;
                        }
                    } else { // if last square is empty, no need to check colour
                        return true;
                    }

                    break;
                case 'B':
                    // moves equally up and down, just check that the path is clear
                    if (move.y > move.newY && move.x > move.newX) { // down and left
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.y--;
                                move.x--;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.y > move.newY && move.x < move.newX) { // down and right
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                move.y--;
                                move.x++;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.y < move.newY && move.x > move.newX) { // up and left
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.y++;
                                move.x--;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.y < move.newY && move.x < move.newX) { // up and right
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                move.y++;
                                move.x++;
                            } else {
                                return false;
                            }
                        }
                    }
                    if (squareArray[move.newX * 8 + move.newY].getPiece() != nullptr) { // if last square is not empty
                        if (currentPiece->getColour() == 'w' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'b') {
                            return true;
                        } else if (currentPiece->getColour() == 'b' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'w') {
                            return true; // return true if opposite colour
                        } else {         // return false if same colour
                            return false;
                        }
                    } else { // if last square is empty, no need to check colour
                        return true;
                    }
                    break;
                case 'N':
                    if (squareArray[move.newX * 8 + move.newY].getPiece() != nullptr) { // if last square is not empty
                        if (currentPiece->getColour() == 'w' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'b') {
                            return true;
                        } else if (currentPiece->getColour() == 'b' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'w') {
                            return true; // return true if opposite colour
                        } else {         // return false if same colour
                            return false;
                        }
                    } else { // if last square is empty, no need to check colour
                        return true;
                    }
                    break;
                case 'K':
                    if (squareArray[move.newX * 8 + move.newY].getPiece() != nullptr) { // if last square is not empty
                        if (currentPiece->getColour() == 'w' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'b') {
                            return true;
                        } else if (currentPiece->getColour() == 'b' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'w') {
                            return true; // return true if opposite colour
                        } else {         // return false if same colour
                            return false;
                        }
                    } else { // if last square is empty, no need to check colour
                        return true;
                    }
                    break;
                case 'Q':
                    // moves equally up and down, just check that the path is clear
                    if (move.y > move.newY && move.x > move.newX) { // down and left
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.y--;
                                move.x--;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.y > move.newY && move.x < move.newX) { // down and right
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                move.y--;
                                move.x++;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.y < move.newY && move.x > move.newX) { // up and left
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.y++;
                                move.x--;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.y < move.newY && move.x < move.newX) { // up and right
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                move.y++;
                                move.x++;
                            } else {
                                return false;
                            }
                        }
                    } else if (move.x == move.newX) { // moving up/down
                        while (move.y != move.newY) { // while not at end location
                            if (move.newY > move.y) { // moving up
                                if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                    move.y++;
                                } else {
                                    return false; // square is occupied
                                }
                            } else if (move.newY < move.y) { // moving down
                                if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                    move.y--;
                                } else {
                                    return false; // square is occupied
                                }
                            }
                        }
                    } else if (move.y == move.newY) { // moving left/right
                        while (move.x != move.newX) { // while not at end location
                            if (move.newX > move.x) { // moving right
                                if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                    move.x++;
                                } else {
                                    return false; // square is occupied
                                }
                            } else if (move.newX < move.x) { // moving left
                                if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                    move.x--;
                                } else {
                                    return false; // square is occupied
                                }
                            }
                        }
                    }
                    if (squareArray[move.newX * 8 + move.newY].getPiece() != nullptr) { // if last square is not empty
                        if (currentPiece->getColour() == 'w' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'b') {
                            return true;
                        } else if (currentPiece->getColour() == 'b' && squareArray[move.newX * 8 + move.newY].getPiece()->getColour() == 'w') {
                            return true; // return true if opposite colour
                        } else {         // return false if same colour
                            return false;
                        }
                    } else { // if last square is empty, no need to check colour
                        return true;
                    }
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
    return false;
}

Board::~Board() {
    delete[] squareArray;
}
