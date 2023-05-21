#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Puzzle.h"
#include <string>

class Game {
private:
    Board currentBoard;
    int turn; // 1 if white, -1 if black
    vector<Move> correctMoveList;
    vector<Move> boardMoves;
    vector<string> boardStates;

public:
    Game();
    Game(char file, Puzzle puzzle);
    bool isInCheck(Move move);
    int playTurn(Move move);
    Board getCurrentBoard();
    int getCorrectMovelistLength();
    vector<Move> getBoardMoves();
    vector<string> getBoardStates();
};

#endif // GAME_H
