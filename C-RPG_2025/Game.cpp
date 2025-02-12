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
	CreateNewCharacter();
}

void Game::MainMenu()
{
	Utils::Print("----------", 2);
	Utils::Print("MAIN MENU");
	Utils::Print("0: Quit");
	Utils::Print("1: Stats");
	Utils::Print("2: Inventory");
	Utils::Print("3: Travel");

	Utils::Print("Your move: ", 0);
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->isPlaying = false;
		break;
	case 1:
		this->character.PrintStats();
		break;
	case 2:
		this->character.PrintInventory();
		break;
	case 3:
		Travel();
		break;
	default:
		Utils::Print(std::to_string(choice) + " is not a valid input. Try something else...");
		break;
	}

	if (isPlaying)
	{
		system("pause");
		system("cls");
	}
}

void Game::CreateNewCharacter()
{
	Utils::Print("===== NEW CHARACTER =====");
	std::string name = Utils::GetInput("Name");
	this->character.Initialize(name, 1);
	Save();
}

void Game::Save()
{
	if (!&this->character.Name())
	{
		return;
	}

	std::string fileName = Paths::SAVE_PATH + this->character.Name() + ".txt";

	if (fileName.size() <= 0)
	{
		return;
	}

	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{
		outFile << this->character.GetAsString();
	}

	outFile.close();
}

void Game::Load()
{
}

void Game::Travel()
{
	this->character.AddDistanceTravelled();
	this->inGameEvent.GenerateEvent(character);
}
