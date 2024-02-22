#include "Entity.h"

Entity::Entity(int row, int col, char symbol)
    : m_row(row), m_col(col), m_symbol(symbol) {}

void Entity::setLocation(int row, int col) {
    m_row = row;
    m_col = col;
}
void Entity::saveLocation(int row, int col) {
    intinalRow = row;
    intinalCol = col;
}

void Entity::reciveIntLocation() {
    m_row = intinalRow;
    m_col = intinalCol;
}

Location Entity::getPosition() const {
    return { m_row, m_col };
}

//Location Entity::calculateNewPosition(const Location& currentPos, direction dir) const {
//    Location newPos = currentPos;
//    switch (dir) {
//    case UP:    newPos.col--; break;
//    case DOWN:  newPos.col++; break;
//    case LEFT:  newPos.row--; break;
//    case RIGHT: newPos.row++; break;
//    }
//    return newPos;
//}
//
//char Entity::getSymbol() const {
//    return m_symbol;
//}

Entity::Entity() {}