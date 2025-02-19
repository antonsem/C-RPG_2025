#include "Game.h"
#include "dArray.h"

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
	dArray<int> testArray;

	for (size_t i = 0; i < 10; i++)
	{
		testArray.Push(i);
	}

	Utils::Print("New array:");
	for (size_t i = 0; i < testArray.Size(); i++)
	{
		Utils::Print(std::to_string(testArray[i]));
	}

	testArray.Remove(5, true);

	Utils::Printn("Removed at 5 ordered");
	for (size_t i = 0; i < testArray.Size(); i++)
	{
		Utils::Print(std::to_string(testArray[i]));
	}

	testArray.Remove(5);

	Utils::Printn("Removed at 5 unordered");
	for (size_t i = 0; i < testArray.Size(); i++)
	{
		Utils::Print(std::to_string(testArray[i]));
	}

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

	choice = Utils::GetInputInt("Your move:", 0, 3);

	switch (choice)
	{
	case 0:
		this->isPlaying = false;
		break;
	case 1:
		this->character.PrintAllStats();
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
		Utils::Clear();
		Save();
	}
}

void Game::CreateNewCharacter()
{
	Utils::Print("===== NEW CHARACTER =====");
	std::string name = Utils::GetInput("Name");
	std::string path = Paths::SAVE_PATH + name + ".txt";
	std::ifstream f(path.c_str());
	bool hasSave = f.good();
	f.close();
	if (hasSave)
	{
		Load(path);
	}
	else
	{
		this->character.Initialize(name, 1);
	}
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

void Game::Load(std::string& filePath)
{
	if (filePath.size() <= 0)
	{
		return;
	}

	std::ifstream inFile(filePath);

	if (inFile.is_open())
	{
		std::string sheet;
		std::getline(inFile, sheet);
		this->character.InitializeFromFile(sheet);

		Utils::Printn("===== CHARACTER LOADED =====");
		this->character.PrintAllStats();
	}

	inFile.close();
}

void Game::Travel()
{
	this->character.AddDistanceTravelled();
	this->inGameEvent.GenerateEvent(character);
}
