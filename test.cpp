#include "Board.h"
#include "Puzzle.h"
#include <iostream>

using namespace std;

int main() {
    Puzzle pa;

    Board b1 = pa.readPuzzle("b");

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
}