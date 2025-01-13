#include "Game.h"

Game::Game()
{
	choice = 0;
	isPlaying = true;
}

Game::~Game()
{
}

void Game::MainMenu()
{
	Utils::Print("----------", 2);
	Utils::Print("MAIN MENU");
	Utils::Print("0: Quit");

	Utils::Print("Your move: ", 0);
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		isPlaying = false;
		break;
	default:
		break;
	}
}
