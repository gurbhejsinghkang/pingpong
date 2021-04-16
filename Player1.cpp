#include "Player1.h"

Player1::Player1(utility::Coordinate headposition, utility::Coordinate tailposition, Direction direction)
	: headposition(headposition),tailposition(tailposition), direction(direction)
{
}

utility::Coordinate Player1::getHeadPosition()
{
	return headposition;
}

utility::Coordinate Player1::getTailPosition()
{
	return tailposition;
}
Direction Player1::getDirection()
{
	return direction;
}

void Player1::move()
{
	if (direction == Direction::Up)
	{
		headposition.Y = headposition.Y -1;
		tailposition.Y = tailposition.Y -1;
	}
	else if (direction == Direction::Down)
	{
		headposition.Y = headposition.Y + 1;
		tailposition.Y = tailposition.Y + 1;
	}
}

void Player1::setDirection(Direction direction)
{
	this->direction = direction;
}
