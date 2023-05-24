#include "Puzzle.h"

Puzzle::Puzzle() {
    currentPieceString = "";
    currentPiece = 0;
    currentSquare = 0;
}

// Since filename is a string, need to take just the first element of the what is
// effectively a character array, and compare those to a series of switch cases
// when fileName is being taken, only these specific inputs are passed through,
// any others lead to either a program exit or another input being taken
Board Puzzle::readPuzzle(string fileName) {
    switch (fileName[0]) {
    case 'a':
    case 'A':
        correctMovelist = {{3, 1, 0, 4}, {0, 4, 0, 7}, {0, 7, 1, 7}};
        boardMoves = {{3, 7, 4, 7}, {1, 0, 1, 7}};
        boardStates = {{"Images/A-1.png"},
                       {"Images/A-2.png"},
                       {"Images/A-3.png"},
                       {"Images/A-4.png"},
                       {"Images/A-5.png"},
                       {"Images/A-6.png"}};
        playerToMove = 1;
        break;
    case 'b':
    case 'B':
        correctMovelist = {{4, 2, 5, 4}, {5, 4, 3, 3}};
        boardMoves = {{4, 6, 4, 5}};
        boardStates = {{"Images/B-1.png"},
                       {"Images/B-2.png"},
                       {"Images/B-3.png"},
                       {"Images/B-4.png"}};
        playerToMove = 1;
        break;
    case 'c':
    case 'C':
        correctMovelist = {{3, 2, 1, 4}, {1, 4, 1, 3}};
        boardMoves = {{3, 7, 3, 6}};
        boardStates = {{"Images/C-1.png"},
                       {"Images/C-2.png"},
                       {"Images/C-3.png"},
                       {"Images/C-4.png"}};
        playerToMove = 1;
        break;
    case 'd':
    case 'D':
        correctMovelist = {{4, 0, 4, 4}, {4, 4, 3, 5}};
        boardMoves = {{5, 2, 6, 2}};
        boardStates = {{"Images/D-1.png"},
                       {"Images/D-2.png"},
                       {"Images/D-3.png"},
                       {"Images/D-4.png"},
                       {"Images/D-5.png"},
                       {"Images/D-6.png"},
                       {"Images/D-7.png"},
                       {"Images/D-8.png"}};
        playerToMove = -1;
        break;
    case 'e':
    case 'E':
        correctMovelist = {{3, 1, 5, 3}, {5, 3, 3, 5}};
        boardMoves = {{4, 4, 7, 4}};
        boardStates = {{"Images/E-1.png"},
                       {"Images/E-2.png"},
                       {"Images/E-3.png"},
                       {"Images/E-4.png"}};
        playerToMove = 1;
        break;
    // Every puzzle has a hard coded move list, series of images, and which colour pieces the player has
    default:
        // Empty stuff if wrong board, won't happen in this program
        std::cout << "Empty board\n";
        correctMovelist = {};
        boardMoves = {};
        boardStates = {};
        playerToMove = 0;
        break;
    }
    Board initialBoard;
    // Read puzzle data from file, which is just 64 rows of what piece is on each square
    ifstream currentPuzzle("Puzzles/" + fileName + ".txt");
    while (getline(currentPuzzle, currentPieceString)) {
        // Pieces are stored as numbers in the text file, so need to convert the string number into an actual integer value
        currentPiece = stoi(currentPieceString);
        initialBoard.getSquareArray()[currentSquare].setPiece(currentPiece);
        currentSquare++;
    }
    return initialBoard; // Returns the newly created puzzle board
}

// Getters
vector<Move> Puzzle::getCorrectMovelist() {
    return correctMovelist;
}

vector<Move> Puzzle::getBoardMoves() {
    return boardMoves;
}

vector<string> Puzzle::getBoardStates() {
    return boardStates;
}

int Puzzle::getPlayerToMove() {
    return playerToMove;
}
