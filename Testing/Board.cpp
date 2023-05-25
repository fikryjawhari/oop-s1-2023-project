#include "Board.h"

Board::Board() {
    squareArray = new Square[64];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squareArray[i * 8 + j].setXPosition(j + 1); // Defining coordinates
            squareArray[i * 8 + j].setYPosition(8 - i); //
        }
    }
}

Square *Board::getSquareArray() {
    return squareArray;
}

// Repeated method that checks if a take is valid
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

// Checks if proposed move is valid on the board;
bool Board::validMove(Move move) {
    // Saves original move location
    Move originalMove = move;
    // Gets piece pointer at given location
    Piece *currentPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    //  Checks if it is an empty square
    if (currentPiece != nullptr) {
        // Call piece valid move function, which uses a 1-8 coordinate instead of 0-7
        bool pieceValidMove = currentPiece->validMove(move.newX + 1, move.newY + 1);
        if (pieceValidMove == true) {
            // Gets piece name, as can't differentiate between derived classes
            char currentPieceType = currentPiece->getPieceType();
            switch (currentPieceType) {
            case 'P':
                // White pawn can take diagonally upwards, and can only take if there is a black piece in that location
                if (currentPiece->getColour() == 'w') {
                    if (move.x != move.newX) {
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) { // If diagonal square we want to go to is not empty
                                if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour() == 'b') {
                                    move.y++;
                                } else {
                                    return false;
                                }
                            } else { // If diagonal square is empty, cannot move diagonally
                                return false;
                            }
                        }
                    } else if (move.x == move.newX) { // Trying to move straight
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y + 1)) * 8 + (move.x)].getPiece() == nullptr) { // If square ahead is empty
                                move.y++;
                            } else {
                                return false;
                            }
                        }
                    }
                } else if (currentPiece->getColour() == 'b') { // Black pawns can take diagonally downwards, and can only move downwards
                    if (move.x != move.newX) {                 // trying to move diagonally
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x + (move.newX - move.x))].getPiece() != nullptr) {
                                if (squareArray[(7 - move.newY) * 8 + move.newX].getPiece()->getColour() == 'w') {
                                    move.y--;
                                } else {
                                    return false;
                                }
                            } else {
                                return false;
                            }
                        }
                    } else if (move.x == move.newX) { // trying to move straight
                        while (move.y != move.newY) {
                            if (squareArray[(7 - (move.y - 1)) * 8 + (move.x)].getPiece() == nullptr) { // if square ahead is empty
                                move.y--;
                            } else {
                                return false;
                            }
                        }
                    }
                }
                return true;
                break;
            // For rook, queen and bishop, since they can move more then
            // 2 squares, need to check if every square along the path is
            // empty, and also if the last square has a takeable piece
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
            case 'Q':
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
                return takeValidation(originalMove);
                break;
            case 'N':
                return takeValidation(originalMove);
                break;
            case 'K':
                return takeValidation(originalMove);
                break;
            }
            // No need to implement default case, only these cases are even possible

        } else { // If piece valid move was false in the first place
            return false;
        }
    } else { // If selected square was empty
        return false;
    }
    return false; // in case nothing triggered a return true or a return false
}

// Method to move piece
void Board::movePiece(Move move) {
    // Takes piece location, moves it to new location and sets old location to null
    Piece *movingPiece = squareArray[(7 - move.y) * 8 + move.x].getPiece();
    squareArray[(7 - move.newY) * 8 + move.newX].setPiecePtr(movingPiece);
    movingPiece->setPosition(move.newX + 1, move.newY + 1);
    squareArray[(7 - move.y) * 8 + move.x].setPiecePtr(nullptr);
}

// Since squareArray is a pointer to an object, any modifications change the object
// itself, so there needs to be a way to fully copy all the data from a new square
// array so that the original data isn't changed. This is needed specifically for a
// method in a different object
void Board::copySquareArray(Square *squareArrayToCopy) {
    int pieceX, pieceY;
    char pieceColour, pieceType;
    for (int i = 0; i < 64; i++) {
        // Initially copy all non-pointer data across
        squareArray[i] = squareArrayToCopy[i];
        // Make new pieces with same data, only if the square has a piece
        if (squareArrayToCopy[i].getPiece() != nullptr) {
            // Gets all required data
            pieceX = squareArrayToCopy[i].getPiece()->getX();
            pieceY = squareArrayToCopy[i].getPiece()->getY();
            pieceColour = squareArrayToCopy[i].getPiece()->getColour();
            pieceType = squareArrayToCopy[i].getPiece()->getPieceType();
            // "Remakes" pieces in object array
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
                squareArray[i].setPiecePtr(nullptr);
                break;
            }
        }
    }
}

// Used in the same method as copySquareArray
void Board::setSquareArray(Square *squareArray) {
    this->squareArray = squareArray;
}

// Used for testing, no longer necessary
void Board::printBoard() {
    for (int i = 0; i < 64; i++) {
        std::cout << squareArray[i].getXPosition() << ", ";
        std::cout << squareArray[i].getYPosition() << ", ";
        std::cout << squareArray[i].getPieceName() << "; ";
        if ((i + 1) % 8 == 0) {
            std::cout << std::endl;
        }
    }
}

Board::~Board() {
    // for (int i = 0; i < 64; i++) {
    //     delete squareArray[i].getPiece();
    // }
    // delete[] squareArray;
}