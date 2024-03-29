#pragma once

#include"Location.h"
//#include"Globals.h"


enum direction { UP, DOWN, LEFT, RIGHT };

class Entity {
public:
    Entity(int row, int col, char symbol);
    Entity();
     void setLocation(int row, int col);
     void saveLocation(int row, int col);
     void reciveIntLocation();
     Location getPosition() const;
    //virtual Location calculateNewPosition(const Location& currentPos, direction dir) const;
    //virtual char getSymbol() const;

protected:
    int intinalRow;
    int intinalCol;
    int m_row;
    int m_col;
    char m_symbol;
};