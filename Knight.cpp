#include "Knight.h"

Knight::Knight(int x, int y, char colour) : Piece(x, y, colour) {
}

bool Knight::validMove(int newX, int newY) {
    if (newX > 0 && newX < 9 && newY > 0 && newY < 9) {
        if ((newY - y == 2 || newY - y == -2) && (newX - x == 1 || newX - x == -1)) {
            return true;
        } else if ((newX - x == 2 || newX - x == -2) && (newY - y == 1 || newY - y == -1)) {
            return true;
        }
    }
    return false;
}

/* y+2 AND (x+1 or x-1) OR y-2 AND (x+1 or x-1)
   x+2 AND (y+1 or y-1) OR x+2 AND (y+1 or y-1)
 */
