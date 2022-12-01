#include "Snake.h"

Snake::Snake(Vector2 pos, int maxTailLength)
{
	this->pos = pos;

	for (int i = 0; i < 50; i++)
		tail[i] = { 0, 0 };

	dir = { 0, 0 };

	curTailLength = 1;
	this->maxTailLength = maxTailLength;
}

Snake::~Snake()
{
}

void Snake::move()
{
	curTailLength++;

	for (int i = curTailLength - 1; i > 0; i--)
		tail[i] = tail[i - 1];

	tail[0] = pos;

	pos.x += dir.x;
	pos.y += dir.y;
}

void Snake::draw()
{
	goToCoordinates(pos);
	std::cout << "*";

	for (int i = 0; i < curTailLength; i++)
	{
		goToCoordinates(tail[i]);
		std::cout << "*";
	}
}

void Snake::turnRight()
{
	if (static_cast<int>(dir.x) == 0)
	{
		dir.y = 0;
		dir.x = 1;
	}
}

void Snake::turnLeft()
{
	if (static_cast<int>(dir.x) == 0)
	{
		dir.y = 0;
		dir.x = -1;
	}
}

void Snake::turnUp()
{
	if (static_cast<int>(dir.y) == 0)
	{
		dir.y = -1;
		dir.x = 0;
	}
}

void Snake::turnDown()
{
	if (static_cast<int>(dir.y) == 0)
	{
		dir.y = 1;
		dir.x = 0;
	}
}