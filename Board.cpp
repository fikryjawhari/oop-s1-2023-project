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

bool Board::takeValidation(Move move) {
    Piece *currentPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    if (currentPiece != nullptr) {
        if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece() != nullptr) { // if last square is not empty
            if (currentPiece->getColour() != squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour()) {
                cout << ", took successfully\n";
                return true;
            } else {
                cout << "and can't take own piece, "; // return false if same colour
                return false;
            }
        }
        cout << ", moved successfully\n";
        return true;
    } else {
        cout << "Empty square ";
        return false;
    }
}

bool Board::validMove(Move move) {
    Move originalMove(move.x, move.y, move.newX, move.newY);
    Piece *currentPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    if (currentPiece != nullptr) {
        bool pieceValidMove = currentPiece->validMove(move.newX + 1, move.newY + 1);
        if (pieceValidMove == true) {
            char currentPieceType = currentPiece->getPieceType();
            switch (currentPieceType) {
            case 'P':
                cout << "Pawn ";
                if (currentPiece->getColour() == 'w') {
                    cout << "W ";
                    if (move.x != move.newX) { // trying to move diagonally
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
                                if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour() == 'b') {             // if piece diagonal is black, can take
                                    move.y++;                                                                                  // this should end loop, cause diagonal move means newY is only 1 bigger
                                } else {
                                    cout << "Can't take own piece "; // if piece diagonal is white, obviously cant move
                                    return false;
                                }
                            } else { // if diagonal square is empty, obviously cant make that move (not implementing en passant)
                                cout << "Can't take empty ";
                                return false;
                            }
                        }
                        cout << "Diagonal Take ";
                    } else if (move.x == move.newX) { // trying to move straight
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead if empty
                                move.y++;
                            } else {
                                cout << "Piece in front ";
                                return false;
                            }
                        }
                        cout << "Straight Move ";
                    }
                } else if (currentPiece->getColour() == 'b') {
                    cout << "B ";
                    if (move.x != move.newX) { // trying to move diagonally
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // if diagonal square we want to go to is not empty
                                if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour() == 'w') {             // if piece diagonal is black, can take
                                    move.y--;                                                                                  // this should end loop, cause diagonal move means newY is only 1 bigger
                                } else {
                                    cout << "Can't take own piece "; // if piece diagonal is white, obviously cant move
                                    return false;
                                }
                            } else // if diagonal square is empty, obviously cant make that move (not implementing en passant)
                                cout << "Can't take empty";
                            return false;
                        }
                        cout << "Diagonal Take ";
                    } else if (move.x == move.newX) { // trying to move straight
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead if empty
                                move.y--;
                            } else {
                                cout << "Piece in front ";
                                return false;
                            }
                        }
                        cout << "Straight Move ";
                    }
                }
                cout << endl;
                return true;
                break;
            case 'R':
                cout << "Rook ";
                if (move.x == move.newX) {        // moving up/down
                    while (move.y != move.newY) { // while not at end location
                        if (move.newY > move.y) { // moving up
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y++;
                            } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        } else if (move.newY < move.y) { // moving down
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y--;
                            } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        }
                    }
                    cout << "Valid Up/Down ";
                } else if (move.y == move.newY) { // moving left/right
                    while (move.x != move.newX) { // while not at end location
                        if (move.newX > move.x) { // moving right
                            if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                move.x++;
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        } else if (move.newX < move.x) { // moving left
                            if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.x--;
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        }
                    }
                    cout << "Valid Left/Right ";
                }
                return takeValidation(originalMove);
                break;
            case 'B':
                cout << "Bishop ";
                // moves equally up and down, just check that the path is clear
                if (move.y > move.newY && move.x > move.newX) { // down and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x--;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Down + Left ";
                } else if (move.y > move.newY && move.x < move.newX) { // down and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x++;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Down + Right ";
                } else if (move.y < move.newY && move.x > move.newX) { // up and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x--;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Up + Left ";
                } else if (move.y < move.newY && move.x < move.newX) { // up and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x++;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Up + Right ";
                }
                return takeValidation(originalMove);
                break;
            case 'N':
                cout << "Knight ";
                return takeValidation(originalMove);
                break;
            case 'K':
                cout << "King ";
                return takeValidation(originalMove);
                break;
            case 'Q':
                cout << "Queen ";
                if (move.y > move.newY && move.x > move.newX) { // down and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x--;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Down + Left ";
                } else if (move.y > move.newY && move.x < move.newX) { // down and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y--;
                            move.x++;
                        } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Down + Right ";
                } else if (move.y < move.newY && move.x > move.newX) { // up and left
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x--;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Up + Left ";
                } else if (move.y < move.newY && move.x < move.newX) { // up and right
                    while (move.y != move.newY) {
                        if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                            move.y++;
                            move.x++;
                        } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                            return (takeValidation(originalMove));
                        } else {
                            cout << "Path Blocked ";
                            return false;
                        }
                    }
                    cout << "Up + Right ";
                } else if (move.x == move.newX) { // moving up/down
                    while (move.y != move.newY) { // while not at end location
                        if (move.newY > move.y) { // moving up
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y++;
                            } else if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        } else if (move.newY < move.y) { // moving down
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) {
                                move.y--;
                            } else if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        }
                    }
                    cout << "Valid Up/Down ";
                } else if (move.y == move.newY) { // moving left/right
                    while (move.x != move.newX) { // while not at end location
                        if (move.newX > move.x) { // moving right
                            if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece() == nullptr) {
                                move.x++;
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x + 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        } else if (move.newX < move.x) { // moving left
                            if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece() == nullptr) {
                                move.x--;
                            } else if (squareArray[(7 - (move.y)) * 8 + (move.x - 1)].getPiece()->getColour() != currentPiece->getColour()) {
                                return (takeValidation(originalMove));
                            } else {
                                cout << "Path Blocked ";
                                return false; // square is occupied
                            }
                        }
                    }
                    cout << "Valid Left/Right ";
                }
                return takeValidation(originalMove);
                break;
            }
        } else {
            cout << "Piece invalid ";
            return false;
        }
    } else {
        cout << "Empty square, no move to make ";
    }
    return false;
}

Board::~Board() {
    delete[] squareArray;
}
