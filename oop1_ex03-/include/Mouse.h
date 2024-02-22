#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include"Location.h"
#include "Entity.h"



class Mouse : public Entity {
public:
	Mouse(int row, int col);
	Mouse();
	// Additional methods specific to Mouse
	Location calculateNewPosition(const Location& currentPos, direction dir) const;
private:
	/*Location position;
	Location m_location;
	Location m_initLocation;*/
};

#endif // MOUSE_H
