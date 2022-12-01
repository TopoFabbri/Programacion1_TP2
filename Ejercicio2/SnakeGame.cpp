#include "SnakeGame.h"

SnakeGame::SnakeGame(int winSnakeLength)
{
	snake = new Snake({ getScreenWidth() / 2, getScreenHeight() / 2 }, 50);
	isGameOver = true;
	hasWon = false;
	this->winSnakeLength = winSnakeLength;
}

SnakeGame::~SnakeGame()
{
	delete snake;
}

void SnakeGame::loop()
{
	do
	{
		play();
	} while (!isGameOver);
}

void SnakeGame::play()
{
	if (isGameOver)
		begin();

	update();

	draw();
}

void SnakeGame::begin()
{
	isGameOver = false;
}

void SnakeGame::update()
{
	input();
}

void SnakeGame::draw()
{
	drawFrame({ 0, 0 }, { getScreenWidth() - 1, getScreenHeight() - 1 });
	snake->draw();
}

void SnakeGame::input()
{
	int key = getKey(false);
}