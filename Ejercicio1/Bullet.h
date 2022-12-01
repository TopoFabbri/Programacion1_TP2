#pragma once

#include "AwesomeLibrary.h"

class Bullet
{
private:
	Vector2 pos;
	static int activeInstances;

public:
	Bullet(Vector2 pos);
	~Bullet();

	void show();
	void hide();
	int getX();
	int getY();
	static int getActiveInstances();
};