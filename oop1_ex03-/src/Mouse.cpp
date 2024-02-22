#include"Mouse.h"

Mouse::Mouse(int row, int col)
    : Entity(row, col, '%') {
    // Additional initialization specific to Mouse, if any
}


Location Mouse::calculateNewPosition(const Location& currentPos, direction dir) const {
    Location newPos = currentPos;
    switch (dir) {
    case UP:    newPos.col--; break;
    case DOWN:  newPos.col++; break;
    case LEFT:  newPos.row--; break;
    case RIGHT: newPos.row++; break;
    }
    return newPos;
}



Mouse::Mouse() {}