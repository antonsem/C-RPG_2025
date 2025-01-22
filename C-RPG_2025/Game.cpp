#include "Game.h"

Game::Game()
{
	this->choice = 0;
	this->isPlaying = true;
}

Game::~Game()
{
}

void Game::InitializeGame()
{
	this->character.Initialize("Anothor", 1);
}

void Game::MainMenu()
{
	Utils::Print("----------", 2);
	Utils::Print("MAIN MENU");
	Utils::Print("0: Quit");
	Utils::Print("1: Stats");

	Utils::Print("Your move: ", 0);
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->isPlaying = false;
		break;
	case 1:
		this->character.PrintStats();
	default:
		break;
	}
}
