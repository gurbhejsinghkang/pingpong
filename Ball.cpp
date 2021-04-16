#include "Ball.h"

Ball::Ball(utility::Coordinate position, Direction directionV, Direction directionH)
	: position(position), directionV(directionV),directionH(directionH)
{
	this->speed = 1;
}

utility::Coordinate Ball::getPosition()
{
	return position;
}

Direction Ball::getHorizontalDirection()
{
	return directionH;
}

Direction Ball::getVerticalDirection()
{
	return directionV;
}

void Ball::move()
{
    if (directionV == Direction::Up)
    {
        position.Y = position.Y - speed;
    }
    if (directionV == Direction::Down)
    {
        position.Y = position.Y + speed;
    }
    if (directionH == Direction::left)
    {
        position.X = position.X - speed;
    }
    if (directionH == Direction::right)
    {
        position.X = position.X + speed;
    }
}

void Ball::setVerticalDirection(Direction direction)
{
	this->directionV = direction;
}

void Ball::setHorizontalDirection(Direction direction)
{
	this->directionH = direction;
}