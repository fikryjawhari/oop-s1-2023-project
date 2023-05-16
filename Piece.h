#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;

class Piece {
protected:
    string colour;
    int x_position;
    int y_position;

public:
    virtual bool validMove() = 0;
};

#endif // PIECE_H
