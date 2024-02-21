#include"Mouse.h"

Mouse::Mouse()
    :m_row(0), m_col(0), m_char(0)
{
    m_location = m_initLocation = Location();
}

//----------------------------------------------------------------

void Mouse::setLocation(const int row, const int col, const  char c) // update the location
{
    m_row = row;
    m_col = col;
    m_char = c;

}

//----------------------------------------------------------------

Location Mouse::getLoc() // get the locationn
{
    struct Location mouseLoc;
    mouseLoc.row = m_row;
    mouseLoc.col = m_col;
    return mouseLoc;
}

//----------------------------------------------------------------

char Mouse::getChar()
{
    return m_char;
}

//----------------------------------------------------------------

void Mouse::setKeyCounter(const int counterkey) // update key number
{
    m_key = counterkey;
}

//----------------------------------------------------------------

int Mouse::getKeyCounter()
{
    return m_key;
}

void Mouse::setPosition(int row, int col) {
    position.row = row;
    position.col = col;
}

Location Mouse::getPosition() {
    return  position;
}

Location Mouse::calculateNewPosition(const Location& currentPos, char direction) const {
    Location newPos = currentPos;
    switch (direction) {
    case 'w': newPos.row--; break; // Move up (decrease row)
    case 's': newPos.row++; break; // Move down (increase row)
    case 'a': newPos.col--; break; // Move left (decrease col)
    case 'd': newPos.col++; break; // Move right (increase col)
    }
    return newPos;
}

Location Mouse::getInitLocation() const
{
    return m_initLocation;
}