#include "Game.h"

using namespace std;

Game::Game() {
    Board emptyBoard;
    currentBoard = emptyBoard;
    turn = 0;
}

// Call read puzzle file and get all necesarry information
Game::Game(std::string fileName) {
    Puzzle p1;
    currentBoard = p1.readPuzzle(fileName);
    turn = p1.getPlayerToMove();
    correctMoveList = p1.getCorrectMovelist();
    boardMoves = p1.getBoardMoves();
    boardStates = p1.getBoardStates();
}

// Function to check if player move caused them to be in check
// This adds some more variety to the players move choice then just a basic
// incorrect/invalid move
bool Game::isInCheck(Move move) {
    // Constructs a temporary board that will act as if the move was taken
    Board tempBoard;
    tempBoard.copySquareArray(currentBoard.getSquareArray());
    if (tempBoard.validMove(move) == true) {
        tempBoard.movePiece(move);
        int kingX = 0;
        int kingY = 0;
        int index = 0;
        bool kingFound = false;
        // First, find which square the player king is
        while (kingFound == false) {
            if (tempBoard.getSquareArray()[index].getPiece() != nullptr) {
                if (tempBoard.getSquareArray()[index].getPieceName() == 'K') {
                    if (tempBoard.getSquareArray()[index].getPiece()->getColour() == 'w' && turn == 1) {
                        kingX = tempBoard.getSquareArray()[index].getXPosition();
                        kingY = tempBoard.getSquareArray()[index].getYPosition();
                        kingFound = true;
                    } else if (tempBoard.getSquareArray()[index].getPiece()->getColour() == 'b' && turn == -1) {
                        kingX = tempBoard.getSquareArray()[index].getXPosition();
                        kingY = tempBoard.getSquareArray()[index].getYPosition();
                        kingFound = true;
                    }
                }
            }
            index++;
        }
        // Check if ANY pieces on the board are able to take the king after the proposed move is made
        tempBoard.printBoard();
        for (int i = 0; i < 64; i++) {
            if (tempBoard.getSquareArray()[i].getPiece() != nullptr) {
                if (tempBoard.getSquareArray()[i].getPiece()->getPieceType() != 'K') {
                    int currentX = tempBoard.getSquareArray()[i].getXPosition();
                    int currentY = tempBoard.getSquareArray()[i].getYPosition();
                    Move tempMove(currentX - 1, currentY - 1, kingX - 1, kingY - 1);
                    if (tempBoard.validMove(tempMove) == true) {
                        return true;
                    } else {
                    }
                }
            }
        }
    }
    // If no conditions were true, then player move did not put them in check
    return false;
}

// Main game loop function
int Game::playTurn(Move move) {
    // Checks first if player move would put them in check
    if (isInCheck(move) == true) {
        std::cout << "In check, please try a different move\n";
        return -1; // in check
    } else {
        // If the move is valid
        if (currentBoard.validMove(move) == true) {
            // If its the correct move for this puzzle
            if (move.moveCompare(correctMoveList[0]) == true) {
                currentBoard.movePiece(move);
                // Could either have a running index of what move we are on, easier
                // to just keep comparing the first element of the vector and deleting
                correctMoveList.erase(correctMoveList.begin());
                return 1; // true/allowed move
            } else {
                std::cout << "Incorrect move, please try again\n";
                return 0; // incorrect move
            }
        } else {
            std::cout << "Invalid move, please try again\n";
            return -2; // invalid move
        }
    }
}

// Getters
Board Game::getCurrentBoard() {
    return currentBoard;
}

int Game::getCorrectMovelistLength() {
    // vector.size() returns a long unsigned int. This assignment is fine since
    // vector size will not be any larger then 10
    int n = correctMoveList.size();
    return n;
}

vector<Move> Game::getBoardMoves() {
    return boardMoves;
}

vector<Move> Game::getCorrectMoves() {
    return correctMoveList;
}

vector<string> Game::getBoardStates() {
    return boardStates;
}

// Show board method. This runs in a thread parallel to main game loop, so that player
// can see direct feedback on their move. This is a basic SFML graphics implementation
void Game::showBoard(int *index) {
    // needed a pointer here as the board state is changing in a seperate thread
    sf::RenderWindow window(sf::VideoMode(700, 700), "Puzzle");
    // positions the window in a nice spot on screen
    window.setPosition(sf::Vector2i(0, 0));
    sf::Texture texture;
    sf::Sprite sprite;
    // If no image was loaded from file, exit method, which in turn exits the program
    if (!texture.loadFromFile(boardStates[*index])) {
        std::cout << "Could not load image" << std::endl;
        return;
    } else {
        sprite.setTexture(texture);
    }
    while (window.isOpen()) {
        sf::Event event;
        // Allows player to close the graphics window
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
        // Loads the image
        window.clear();
        window.draw(sprite);
        window.display();

        // Reassigns image in case it was changed
        if (!texture.loadFromFile(boardStates[*index])) {
            std::cout << "Could not load image" << std::endl;
            return;
        } else {
            sprite.setTexture(texture);
        }
    }
    return;
}