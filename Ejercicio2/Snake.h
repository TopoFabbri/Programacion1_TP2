#pragma once

#include "AwesomeLibrary.h"

class Snake
{
private:
	int curTailLength;
	int maxTailLength;
	
	Vector2 dir;
	Vector2 pos;
	Vector2 tail[50];

public:
	Snake(Vector2 pos, int maxTailLength);
	~Snake();

	void move();
	void draw();

	void turnRight();
	void turnLeft();
	void turnUp();
	void turnDown();
};