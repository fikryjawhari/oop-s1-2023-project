#ifndef PUZZLE_H
#define PUZZLE_H

#include "Bishop.h"
#include "Board.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Square.h"
#include "Window.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Puzzle {
public:
    string currentPieceString = "";
    int currentPiece = 0;
    int currentSquare = 0;
    Board readPuzzle(string fileName) {
        Board initialBoard;
        Square *initialBoardArray = initialBoard.getSquareArray();
        ifstream currentPuzzle(fileName + ".txt");
        if (currentPuzzle.is_open() == false) {
            cout << "No such puzzle file exists, displaying empty board.\n";
            return initialBoard;
        } else {
            while (getline(currentPuzzle, currentPieceString)) {
                currentPiece = stoi(currentPieceString);
                initialBoardArray[currentSquare].setPiece(currentPiece);
                currentSquare++;
            }
            return initialBoard;
        }
    }
};

#endif // PUZZLE_H
