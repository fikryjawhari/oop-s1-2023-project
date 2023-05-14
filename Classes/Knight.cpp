#include "Knight.h"

bool Knight::validMove(int x_pos, int y_pos) {
    if (x_pos > 0 && x_pos < 9 && y_pos > 0 && y_pos < 9) {
        if ((y_pos - y_position == 2 || y_pos - y_position == -2) && (x_pos - x_position == 1 || x_pos - x_position == -1)) {
            return true;
        } else if ((x_pos - x_position == 2 || x_pos - x_position == -2) && (y_pos - y_position == 1 || y_pos - y_position == -1)) {
            return true;
        }
    }
    return false;
}

/* y+2 AND (x+1 or x-1) OR y-2 AND (x+1 or x-1)
   x+2 AND (y+1 or y-1) OR x+2 AND (y+1 or y-1)
 */

Knight::Knight(int x_position, int y_position, string colour) {
    this->x_position = x_position;
    this->y_position = y_position;
    this->colour = colour;
}

Knight::Knight() {
}
