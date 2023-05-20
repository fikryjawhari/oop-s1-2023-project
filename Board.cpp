#include "Board.h"
#include "Piece.h"

using namespace std;

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

bool Board::takeValidation(Move move) {
    Piece *currentPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    if (currentPiece != nullptr) {
        if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece() != nullptr) { // if last square is not empty
            if (currentPiece->getColour() != squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour()) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool Board::validMove(Move move) {
    Move originalMove = move;
    Piece *currentPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    if (currentPiece != nullptr) {
        bool pieceValidMove = currentPiece->validMove(move.newX + 1, move.newY + 1);
        if (pieceValidMove == true) {
            char currentPieceType = currentPiece->getPieceType();
            switch (currentPieceType) {
            case 'P':
                if (currentPiece->getColour() == 'w') {
                    if (move.x != move.newX) { // trying to move diagonally
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
                                if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour() == 'b') {             // if piece diagonal is black, can take
                                    move.y++;                                                                                  // this should end loop, cause diagonal move means newY is only 1 bigger
                                } else {
                                    return false;
                                }
                            } else { // if diagonal square is empty, obviously cant make that move (not implementing en passant)
                                return false;
                            }
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
                                if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour() == 'w') {             // if piece diagonal is black, can take
                                    move.y--;                                                                                  // this should end loop, cause diagonal move means newY is only 1 bigger
                                } else {
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
                if (move.x == move.newX) {        // moving up/down
                    while (move.y != move.newY) { // while not at end location
                        if (move.newY > move.y) { // moving up
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y++;
                            } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                return false; // square is occupied
                            }
                        } else if (move.newY < move.y) { // moving down
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y--;
                            } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
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
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                return false; // square is occupied
                            }
                        } else if (move.newX < move.x) { // moving left
                            if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.x--;
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                return false; // square is occupied
                            }
                        }
                    }
                }
                return takeValidation(originalMove);
                break;
            case 'B':
                // moves equally up and down, just check that the path is clear
                if (move.y > move.newY && move.x > move.newX) { // down and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x--;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                } else if (move.y > move.newY && move.x < move.newX) { // down and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x++;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                } else if (move.y < move.newY && move.x > move.newX) { // up and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x--;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                } else if (move.y < move.newY && move.x < move.newX) { // up and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x++;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                }
                return takeValidation(originalMove);
                break;
            case 'N':
                return takeValidation(originalMove);
                break;
            case 'K':
                return takeValidation(originalMove);
                break;
            case 'Q':
                cout << "Queen, ";
                if (move.y > move.newY && move.x > move.newX) { // down and left
                    cout << "down+left, ";
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x--;
                            cout << "next box empty\n";
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            cout << "next box has takeable piece\n";
                            return (takeValidation(originalMove));
                        } else {
                            cout << "next box has own piece\n";
                            return false;
                        }
                    }
                } else if (move.y > move.newY && move.x < move.newX) { // down and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x++;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                } else if (move.y < move.newY && move.x > move.newX) { // up and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x--;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                } else if (move.y < move.newY && move.x < move.newX) { // up and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x++;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            return false;
                        }
                    }
                } else if (move.x == move.newX) { // moving up/down
                    while (move.y != move.newY) { // while not at end location
                        if (move.newY > move.y) { // moving up
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y++;
                            } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                return false; // square is occupied
                            }
                        } else if (move.newY < move.y) { // moving down
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y--;
                            } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
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
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                return false; // square is occupied
                            }
                        } else if (move.newX < move.x) { // moving left
                            if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.x--;
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                return false; // square is occupied
                            }
                        }
                    }
                }
                cout << "Success";
                return takeValidation(originalMove);
                break;
            }
        } else {
            return false;
        }
    } else {
    }
    return false;
}

// For board, need to add a check for making sure the king is not in check
// can do this by 'imagining' the move, and then seeing if next turn
// its possible to take the king, where we add that if around the whole thing

void Board::movePiece(Move move) {
    Piece *movingPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    squareArray[(7 - move.newY) * 8 + move.newX].setPiecePtr(movingPiece);
    movingPiece->setPosition(move.newX + 1, move.newY + 1);
    squareArray[(7 - move.y) * 8 + move.x].setPiecePtr(nullptr);
}

void Board::printBoard() {
    for (int i = 0; i < 64; i++) {
        if (squareArray[i].getPiece() != nullptr) {
            cout << squareArray[i].getXPosition() << ",";
            cout << squareArray[i].getYPosition() << ",";
            cout << squareArray[i].getPiece()->getPieceType();
            if ((i + 1) % 8 == 0) {
                cout << endl;
            } else {
                cout << "; ";
            }
        } else {
            cout << squareArray[i].getXPosition() << ",";
            cout << squareArray[i].getYPosition();
            if ((i + 1) % 8 == 0) {
                cout << endl;
            } else {
                cout << "; ";
            }
        }
    }
}

void Board::copySquareArray(Square *squareArrayToCopy) {
    int pieceX, pieceY;
    char pieceColour, pieceType;
    for (int i = 0; i < 64; i++) {
        squareArray[i] = squareArrayToCopy[i];
        if (squareArrayToCopy[i].getPiece() != nullptr) {
            pieceX = squareArrayToCopy[i].getPiece()->getX();
            pieceY = squareArrayToCopy[i].getPiece()->getY();
            pieceColour = squareArrayToCopy[i].getPiece()->getColour();
            pieceType = squareArrayToCopy[i].getPiece()->getPieceType();
            switch (pieceType) {
            case 'P':
                squareArray[i].setPiecePtr(new Pawn{pieceX, pieceY, pieceColour});
                break;
            case 'R':
                squareArray[i].setPiecePtr(new Rook{pieceX, pieceY, pieceColour});
                break;
            case 'B':
                squareArray[i].setPiecePtr(new Bishop{pieceX, pieceY, pieceColour});
                break;
            case 'N':
                squareArray[i].setPiecePtr(new Knight{pieceX, pieceY, pieceColour});
                break;
            case 'K':
                squareArray[i].setPiecePtr(new King{pieceX, pieceY, pieceColour});
                break;
            case 'Q':
                squareArray[i].setPiecePtr(new Queen{pieceX, pieceY, pieceColour});
                break;
            default:
                break;
            }
        }
    }
}

void Board::setSquareArray(Square *squareArray) {
    this->squareArray = squareArray;
}

// Board::~Board() {
//     delete[] squareArray;
// }
