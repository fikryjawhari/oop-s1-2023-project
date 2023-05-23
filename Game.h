// Defining Game
#ifndef GAME_H
#define GAME_H

// Displaying images
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Puzzle contains all other necesarry headers
#include "Puzzle.h"

// Declaring class including data members and methods
class Game {
private:
    Board currentBoard;
    int turn; // 1 if white, -1 if black

    // Store various data needed from the puzzles
    vector<Move> correctMoveList;
    vector<Move> boardMoves;
    vector<string> boardStates;

public:
    // Constructors
    Game();
    Game(std::string fileName, Puzzle puzzle);
    // Various functions for core game loop
    bool isInCheck(Move move);
    int playTurn(Move move);
    // Getters
    Board getCurrentBoard();
    int getCorrectMovelistLength();
    vector<Move> getBoardMoves();
    vector<Move> getCorrectMoves();
    vector<string> getBoardStates();
    // Displaying image of the board
    void showBoard(int *index);
};

#endif // GAME_H
