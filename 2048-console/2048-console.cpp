#include "Game.h"
#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    Grid grid;
    Game game;
    Test test;
    test.IntegrationTest1();
    test.IntegrationTest2();
    test.IntegrationTest3();
    test.IntegrationTest4();
    test.IntegrationTest5();
    game.GameLoop();
}