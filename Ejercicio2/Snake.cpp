#include "Snake.h"

Snake::Snake(Vector2 pos, int maxTailLength)
{
	this->pos = pos;

	for (int i = 0; i < 50; i++)
		tail[i] = { 0, 0 };

	curTailLength = 0;
	this->maxTailLength = maxTailLength;
	speed = 1;
}

Snake::~Snake()
{
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
	tail[curTailLength] = pos;

	pos.x++;
	curTailLength++;
}

void Snake::turnLeft()
{
	tail[curTailLength] = pos;

	pos.x--;
	curTailLength++;
}

void Snake::turnUp()
{
	tail[curTailLength] = pos;

	pos.y--;
	curTailLength++;
}

void Snake::turnDown()
{
	tail[curTailLength] = pos;

	pos.y++;
	curTailLength++;
}

int Snake::getLength()
{
	return curTailLength;
}

Vector2 Snake::getPos()
{
	return pos;
}

bool Snake::tailColliding()
{
	for (int i = 0; i < curTailLength; i++)
	{
		if (tail[i].x == pos.x && tail[i].y == pos.y)
			return true;
	}

	return false;
}