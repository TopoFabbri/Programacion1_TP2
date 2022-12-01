#include "Bullet.h"

int Bullet::activeInstances = 0;

Bullet::Bullet(Vector2 pos)
{
	this->pos = pos;
	activeInstances++;
}

Bullet::~Bullet()
{
	activeInstances--;
}

void Bullet::show()
{
	goToCoordinates(pos);
	std::cout << "O";
}

void Bullet::hide()
{
	goToCoordinates(pos);
	std::cout << " ";
}

int Bullet::getX()
{
	return pos.x;
}

int Bullet::getY()
{
	return pos.y;
}

int Bullet::getActiveInstances()
{
	return activeInstances;
}