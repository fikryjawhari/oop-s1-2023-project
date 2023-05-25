
#ifndef PUZZLE_H
#define PUZZLE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Board.h"

using namespace std;

class Puzzle {
private:
    string currentPieceString;
    int currentPiece, currentSquare;
    vector<Move> correctMovelist, boardMoves; // Board move stores moves that player doesn't control
    vector<string> boardStates;
    int playerToMove; // 1 if white, -1 if black

public:
    Puzzle();
    // Reads puzzle from file
    Board readPuzzle(string fileName);
    // Getters
    vector<Move> getCorrectMovelist();
    vector<Move> getBoardMoves();
    vector<string> getBoardStates();
    int getPlayerToMove();
};

#endif // PUZZLE_H
