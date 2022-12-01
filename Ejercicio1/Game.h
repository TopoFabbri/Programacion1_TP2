#pragma once

#include "AwesomeLibrary.h"
#include "Bullet.h"

class Game
{
private:
	bool isPlaying;
	bool hideBullets;
	static const int bulQty = 3;
	Bullet* bul[bulQty];

public:
	Game();
	~Game();

	void loop();
	void play();

	void begin();
	void update();
	void draw();

	Vector2 getRandomPosition();
	bool checkPosOverlaps(Vector2 pos);
};