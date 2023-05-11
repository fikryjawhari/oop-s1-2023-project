#include "Queen.h"
#include <cmath>

bool Queen::validMove(int x_pos, int y_pos) {               // copies valid move checks from bishop and rook
    if (x_pos > 0 && x_pos < 9 && y_pos > 0 && y_pos < 9) { // Within board confines
        if (y_pos - y_position != 0 && x_pos - x_position == 0) {
            if (abs(y_pos - y_position) <= maxMoveDistance) {
                return true;
            }
        } else if (y_pos - y_position == 0 & x_pos - x_position != 0) {
            if (abs(y_pos - y_position) <= maxMoveDistance) {
                return true;
            }
        } else if ((y_position - y_pos) == (x_position - x_pos) || (y_position - y_pos) == (x_pos - x_position)) { // if absolute x movement is same as y movement
            if (abs(y_pos - y_position) <= maxMoveDistance) {
                return true;
            }
        }
    }
}

Queen::Queen(int x_position, int y_position, string colour) {
    this->x_position = x_position;
    this->y_position = y_position;
    this->colour = colour;
    maxMoveDistance = 7;
}
