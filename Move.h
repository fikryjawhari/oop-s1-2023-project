#ifndef MOVE_H
#define MOVE_H

struct Move {
    int x, y, newX, newY;
    Move(){};
    Move(int x, int y, int newX, int newY);
};

#endif // MOVE_H
