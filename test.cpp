#include "Board.h"
#include "Puzzle.h"
#include <iostream>

using namespace std;

int main() {
    Board b1;
    Puzzle pa;

    b1 = pa.readPuzzle('a');

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << b1.getSquareArray()[i * 8 + j].getXPosition() << ", ";
            cout << b1.getSquareArray()[i * 8 + j].getYPosition() << ", ";
            cout << b1.getSquareArray()->getPiece() << endl;
        }
    }
}