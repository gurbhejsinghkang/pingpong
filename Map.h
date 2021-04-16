#pragma once
#include "Coordinate.h"

class Map
{
private:
	utility::Coordinate topLeft;
	utility::Coordinate bottomRight;
	utility::Coordinate topRight;
	utility::Coordinate bottomLeft;
	utility::Coordinate left;
	utility::Coordinate right;
	utility::Coordinate size;

public:
	Map(utility::Coordinate topLeft, utility::Coordinate bottomRight);
	utility::Coordinate getTopLeft();
	utility::Coordinate getBottomRight();
	utility::Coordinate getTopRight();
	utility::Coordinate getBottomLeft();
	utility::Coordinate getLeft();
	utility::Coordinate getRight();
	utility::Coordinate getSize();
};
