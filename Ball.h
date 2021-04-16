#pragma once
#include "Coordinate.h"
#include "Direction.h"
using namespace utility;
class Ball
{
private:
	utility::Coordinate position;
	Direction directionV,directionH;
	double speed;
public:
	Ball(utility::Coordinate position, Direction directionV, Direction directionH);
	utility::Coordinate getPosition();
	Direction getHorizontalDirection();
	Direction getVerticalDirection();
	void move();
	void setVerticalDirection(Direction direction);
	void setHorizontalDirection(Direction direction);
};

