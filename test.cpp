#include "Board.h"
#include "Move.h"
#include "Puzzle.h"
#include <iostream>

using namespace std;

int main() {
    Puzzle pa;

    Board b1 = pa.readPuzzle("a");

    // for (int i = 0; i < 64; i++) {
    //     if (b1.getSquareArray()[i].getPiece() != nullptr) {
    //         cout << b1.getSquareArray()[i].getXPosition() << ", ";
    //         cout << b1.getSquareArray()[i].getYPosition() << ", ";
    //         cout << b1.getSquareArray()[i].getPiece()->getPieceType();
    //         cout << endl;
    //     } else {
    //         cout << b1.getSquareArray()[i].getXPosition() << ", ";
    //         cout << b1.getSquareArray()[i].getYPosition() << endl;
    //     }
    // }
    int n = 9;
    Move pawnMoveList[n] = {
        {6, 1, 6, 2},
        {6, 1, 6, 3},
        {6, 6, 6, 5},
        {6, 6, 6, 4},
        {4, 3, 4, 4},
        {5, 2, 5, 3},
        {5, 2, 5, 4},
        {5, 2, 4, 3},
        {5, 2, 6, 3}};
    cout << "Succesfully allocated moves\n";
    for (int i = 0; i < n; i++) {
        if (b1.validMove(pawnMoveList[i]) == true) {
            cout << "Board valid move\n";
        } else {
            cout << "Board invalid move\n";
        }
    }
    return 0;
}