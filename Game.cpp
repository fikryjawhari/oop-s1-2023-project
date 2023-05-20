#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {
    Board emptyBoard;
    currentBoard = emptyBoard;
    turn = 0;
}

Game::Game(int turn, std::string fileName, Puzzle puzzle) {
    this->turn = turn;
    currentBoard = puzzle.readPuzzle(fileName);
    correctMoveList = puzzle.getCorrectMovelist();
    boardHistory.push_back(currentBoard);
}

bool Game::isInCheck(Move move) {
    Board tempBoard;
    tempBoard.copySquareArray(currentBoard.getSquareArray());
    if (tempBoard.validMove(move) == true) {
        tempBoard.movePiece(move);
        int kingX = 0;
        int kingY = 0;
        int index = 0;
        bool kingFound = false;
        while (kingFound == false) {
            if (tempBoard.getSquareArray()[index].getPiece() != nullptr) {
                if (tempBoard.getSquareArray()[index].getPieceName() == 'K') {
                    if (tempBoard.getSquareArray()[index].getPiece()->getColour() == 'w' && turn == 1) {
                        kingX = tempBoard.getSquareArray()[index].getPiece()->getX();
                        kingY = tempBoard.getSquareArray()[index].getPiece()->getY();
                        kingFound = true;
                    } else if (tempBoard.getSquareArray()[index].getPiece()->getColour() == 'b' && turn == -1) {
                        kingX = tempBoard.getSquareArray()[index].getPiece()->getX();
                        kingY = tempBoard.getSquareArray()[index].getPiece()->getY();
                        kingFound = true;
                    }
                }
            }
            index++;
        }
        for (int i = 0; i < 64; i++) {
            if (tempBoard.getSquareArray()[i].getPiece() != nullptr) {
                if (tempBoard.getSquareArray()[i].getPiece()->getPieceType() != 'K') {
                    int currentX = tempBoard.getSquareArray()[i].getPiece()->getX();
                    int currentY = tempBoard.getSquareArray()[i].getPiece()->getY();
                    // cout << currentX << ", " << currentY << ", next piece\n";
                    Move tempMove(currentX - 1, currentY - 1, kingX - 1, kingY - 1);
                    // cout << "Made move, " << i << endl;
                    if (tempBoard.validMove(tempMove) == true) {
                        cout << tempBoard.getSquareArray()[i].getPiece()->getColour();
                        cout << tempBoard.getSquareArray()[i].getPieceName();
                        cout << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int Game::playTurn(Move move) {
    if (isInCheck(move) == true) {
        std::cout << "In check, please try a different move\n";
        return -1; // in check
    } else {
        if (currentBoard.validMove(move) == true) {
            if (move.moveCompare(correctMoveList[0]) == true) {
                currentBoard.movePiece(move);
                correctMoveList.erase(correctMoveList.begin());
                boardHistory.push_back(currentBoard);
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

Board Game::getCurrentBoard() {
    return currentBoard;
}

int Game::getCorrectMovelistLength() {
    int n = correctMoveList.size();
    return n;
}