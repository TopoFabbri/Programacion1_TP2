#include "SnakeGame.h"

SnakeGame::SnakeGame(int winSnakeLength)
{
	deltaClock = 0;
	delta = static_cast<float>(clock()) / 1000;
	frames = 0;
	fps = 30;
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
	delta = 1;

	do
	{
		play();
	} while (!isGameOver);
}

void SnakeGame::play()
{
	if (isGameOver)
		begin();

	delta = getTime() - deltaClock;

	if (delta * 60 >= 1)
	{
		deltaClock = getTime();

		update();

		draw();
	}
}

void SnakeGame::begin()
{
	isGameOver = false;
}

void SnakeGame::update()
{
	input();

	if (snake->getLength() >= winSnakeLength)
	{
		isGameOver = true;
		hasWon = true;
	}

	if (snake->tailColliding() || snakeMapColliding())
		isGameOver = true;
}

void SnakeGame::draw()
{
	drawFrame({ 0, 0 }, { getScreenWidth() - 1, getScreenHeight() - 1 });
	snake->draw();

	goToCoordinates({ 1, 1 });
	std::cout << snake->getLength();

	if (isGameOver)
	{
		clearScreen();

		std::cout << (hasWon ? "You win!" : "You lose!") << "Snake length: " << snake->getLength() << "\n\n";

		system("pause");
	}
}

void SnakeGame::input()
{
	int key = getKey(false);

	if (key == 'a')
		snake->turnLeft();

	if (key == 'd')
		snake->turnRight();

	if (key == 'w')
		snake->turnUp();

	if (key == 's')
		snake->turnDown();
}

bool SnakeGame::snakeMapColliding()
{
	return (snake->getPos().x <= 0 ||
		snake->getPos().x >= getScreenWidth() - 1 ||
		snake->getPos().y <= 0 ||
		snake->getPos().y >= getScreenHeight() - 1);
}

float SnakeGame::getTime()
{
	return static_cast<float>(clock()) / 1000;
}