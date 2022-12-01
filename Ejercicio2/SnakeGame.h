#pragma once

#include "AwesomeLibrary.h"
#include "Snake.h"

class SnakeGame
{
private:
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
};
