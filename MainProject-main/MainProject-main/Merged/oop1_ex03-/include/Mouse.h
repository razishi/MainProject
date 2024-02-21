#pragma once
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include"Location.h"

enum direction { UP, DOWN, LEFT, RIGHT };

class Mouse
{
public:
	Mouse();
	void setLocation(const int row, const int col, const char c);
	Location getLoc();
	char getChar();
	void setKeyCounter(const int counterkey);
	int getKeyCounter();
	void setPosition(int row, int col);
	Location getPosition();
	Location calculateNewPosition(const Location& currentPos, enum direction) const;
	Location getInitLocation() const;


private:

	int m_row;
	int m_col;
	char m_char;
	int m_key = 0;
	Location position;
	Location m_location;
	Location m_initLocation;
};