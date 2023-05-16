#include "Board.h"
#include <iostream>

using namespace std;

int main() {
    Board b1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << b1.getSquareArray()[i * 8 + j].getXPosition() << "," << b1.getSquareArray()[i * 8 + j].getYPosition() << endl;
        }
    }
}