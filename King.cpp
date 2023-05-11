#include "King.h"

King::King(int x_position, int y_position, string colour) : Queen(x_position, y_position, colour) {
    maxMoveDistance = 1;
}
