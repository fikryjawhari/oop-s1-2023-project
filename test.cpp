#include "Board.h"
#include "Move.h"
#include "Puzzle.h"
#include <iostream>

using namespace std;

int main() {
    Puzzle pa;

    Board b1 = pa.readPuzzle("a");

    for (int i = 0; i < 64; i++) {
        if (b1.getSquareArray()[i].getPiece() != nullptr) {
            cout << b1.getSquareArray()[i].getXPosition() << ", ";
            cout << b1.getSquareArray()[i].getYPosition() << ", ";
            cout << b1.getSquareArray()[i].getPiece()->getPieceType();
            cout << endl;
        } else {
            cout << b1.getSquareArray()[i].getXPosition() << ", ";
            cout << b1.getSquareArray()[i].getYPosition() << endl;
        }
    }
    vector<Move> moveList =
        {
            {1, 7, 0, 7}, // blocked invalid
            {1, 7, 7, 7}, // left/right valid
            {1, 7, 1, 8}, // piece invalid
            {1, 7, 1, 6}, // up/down valid
            {1, 7, 1, 2}, // take valid
            {1, 7, 2, 2}, // move invalid
            {4, 2, 5, 3}, // invalid, cant take own piece
            {4, 2, 5, 4}, // invalid move
            {4, 2, 3, 3}, //
            {4, 2, 0, 6},
            {4, 2, 5, 1},
            {4, 2, 6, 0},
            {4, 2, 3, 1},
            {4, 2, 2, 0},

        };
    int n = moveList.size();
    cout << "Succesfully allocated moves\n";
    for (int i = 0; i < n; i++) {
        if (b1.validMove(moveList[i]) != true) {
            cout << "Moved unsuccessfully\n";
        } else {
            b1.movePiece(moveList[i]);
            cout << "Moved successfully\n";
        }
    }
    for (int i = 0; i < 64; i++) {
        if (b1.getSquareArray()[i].getPiece() != nullptr) {
            cout << b1.getSquareArray()[i].getXPosition() << ", ";
            cout << b1.getSquareArray()[i].getYPosition() << ", ";
            cout << b1.getSquareArray()[i].getPiece()->getPieceType();
            cout << endl;
        } else {
            cout << b1.getSquareArray()[i].getXPosition() << ", ";
            cout << b1.getSquareArray()[i].getYPosition() << endl;
        }
    }
    return 0;
}