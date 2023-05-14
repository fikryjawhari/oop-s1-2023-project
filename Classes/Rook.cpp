#include "Rook.h"

bool Rook::validMove(int x_pos, int y_pos) // y increase -> no x increase OR x increase -> no y increase
{
    if (x_pos > 0 && x_pos < 9 && y_pos > 0 && y_pos < 9) { // Within board confines
        if (y_pos - y_position != 0 && x_pos - x_position == 0) {
            return true;
        } else if (y_pos - y_position == 0 & x_pos - x_position != 0) {
            return true;
            /*   If time, add castle functoinality, otherwise dont have any puzzles that require castling
            } else if (colour == "w") {
                if ((x_position == 1 || x_position == 8) && )
            }
            */
        }
        return false;
    }
}
Rook::Rook() {
}

Rook::Rook(int x_position, int y_position, string colour) {
    this->x_position = x_position;
    this->y_position = y_position;
    this->colour = colour;
}
