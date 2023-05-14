#ifndef ROW_H
#define ROW_H

#include "Square.h"

class Row {
private:
    Square *squareArray;

public:
    Row();
    Square *getRow();
    void setRow(int yPosition);
    ~Row();
};

#endif // ROW_H
