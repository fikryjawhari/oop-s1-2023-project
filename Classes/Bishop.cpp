#include "Bishop.h"

bool Bishop::validMove(int x_pos, int y_pos) // y increase = x increse/x decrease
{
    if (x_pos > 0 && x_pos < 9 && y_pos > 0 && y_pos < 9) {
        if ((y_position - y_pos) == (x_position - x_pos) || (y_position - y_pos) == (x_pos - x_position)) { // if absolute x movement is same as y movement
            return true;
        }
    }
    return false;
}

Bishop::Bishop() {
}

Bishop::Bishop(int x_position, int y_position, string colour) {
    this->x_position = x_position;
    this->y_position = y_position;
    this->colour = colour;
}
