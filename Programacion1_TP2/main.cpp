#include <iostream>
#include <ctime>

#include "SnakeGame.h"

void runProgram();
void defaults();

void main()
{
    runProgram();
}

void runProgram()
{
    defaults();
    SnakeGame* game = new SnakeGame(50);
    game->loop();
    delete game;
}

void defaults()
{
    srand(time(nullptr));
    hideCursor();
}