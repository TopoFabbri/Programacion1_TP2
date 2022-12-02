#pragma once

#include "AwesomeLibrary.h"

class Snake
{
private:
	int curTailLength;
	int maxTailLength;
	float speed;
	
	Vector2 pos;
	Vector2 tail[400];

public:
	Snake(Vector2 pos, int maxTailLength);
	~Snake();

	void draw();

	void turnRight();
	void turnLeft();
	void turnUp();
	void turnDown();

	int getLength();
	Vector2 getPos();

	bool tailColliding();
};