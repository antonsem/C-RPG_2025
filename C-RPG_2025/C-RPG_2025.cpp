// C-RPG_2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Game.h"

int main()
{
	Game game;
	game.InitializeGame();

	while (game.IsPlaying())
	{
		game.MainMenu();
	}

	return 0;
}

