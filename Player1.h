#pragma once
#include "Coordinate.h"
#include<vector>
#include "Direction.h"
class Player1
{
private:
	utility::Coordinate headposition;
	utility::Coordinate tailposition;
	Direction direction;
public:
	Player1(utility::Coordinate headposition,
		utility::Coordinate tailposition,
		Direction direction);
	utility::Coordinate getHeadPosition();
	utility::Coordinate getTailPosition();
	Direction getDirection();
	void move();
	void setDirection(Direction direction);
};