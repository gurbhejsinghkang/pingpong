#include "Map.h"
using utility::Coordinate;

Map::Map(Coordinate topLeft, Coordinate bottomRight)
	: topLeft(topLeft),
	bottomRight(bottomRight),
	topRight(bottomRight.X, topLeft.Y),
	bottomLeft(topLeft.X, bottomRight.Y),
	left(left),
	right(right),
	size(bottomRight.X - topLeft.X + 1, bottomRight.Y - topLeft.Y + 1)
{ 

}

Coordinate Map::getTopLeft()
{
	return topLeft;
}

Coordinate Map::getBottomRight()
{
	return bottomRight;
}

Coordinate Map::getTopRight()
{
	return topRight;
}

Coordinate Map::getBottomLeft()
{
	return bottomLeft;
}

utility::Coordinate Map::getLeft()
{
	return left;
}

utility::Coordinate Map::getRight()
{
	return right;
}

Coordinate Map::getSize()
{
	return size;
}
