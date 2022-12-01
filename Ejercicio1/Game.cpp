#include "Game.h"

Game::Game()
{
	isPlaying = false;
	hideBullets = false;

	for (int i = 0; i < bulQty; i++)
	{
		Vector2 newPos{};

		do
		{
			newPos = getRandomPosition();
		} while (checkPosOverlaps(newPos));

		bul[i] = new Bullet(newPos);
	}
}

Game::~Game()
{
	clearScreen();

	for (int i = 0; i < Bullet::getActiveInstances(); i++)
	{
		delete bul[i];
	}
}

void Game::loop()
{
	do
	{
		play();
	} while (isPlaying);
}

void Game::play()
{
	// Begin
	if (!isPlaying)
		begin();

	// Update
	update();

	// Draw
	draw();
}

void Game::begin()
{
	isPlaying = true;

	for (int i = 0; i < Bullet::getActiveInstances(); i++)
		bul[i]->show();
}

void Game::update()
{
	int key = getKey(false);

	if (key == ' ')
	{
		if (Bullet::getActiveInstances() > 0)
		{
			bul[Bullet::getActiveInstances() - 1]->hide();
			delete bul[Bullet::getActiveInstances() - 1];
		}
		else
		{
			isPlaying = false;
		}
	}
}

void Game::draw()
{
	drawFrame({ 0, 1 }, { getScreenWidth() - 1, getScreenHeight() - 1 });
	goToCoordinates({ 0, 0 });
	std::cout << Bullet::getActiveInstances();
}

Vector2 Game::getRandomPosition()
{
	Vector2 pos;

	pos.x = (float)(rand() % ((int)getScreenWidth() - 2) + 1);
	pos.y = (float)(rand() % ((int)getScreenHeight() - 2) + 2);

	return pos;
}

bool Game::checkPosOverlaps(Vector2 pos)
{
	for (int i = 0; i < Bullet::getActiveInstances(); ++i)
	{
		if ((int)pos.x == (int)bul[i]->getX() && (int)pos.y == (int)bul[i]->getY())
			return true;
	}

	return false;
}