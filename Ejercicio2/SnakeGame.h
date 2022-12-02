#pragma once

#include "AwesomeLibrary.h"
#include "Snake.h"

class SnakeGame
{
private:
	float deltaClock;
	float delta;
	int frames;
	int fps;

	bool isGameOver;
	bool hasWon;
	int winSnakeLength;

	Snake* snake;

public:
	SnakeGame(int winSnakeLength);
	~SnakeGame();

	void loop();
	void play();

	void begin();
	void update();
	void draw();

	void input();
	bool snakeMapColliding();

	float getTime();
};