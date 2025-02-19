#pragma once

#include <fstream>
#include "Character.h"
#include "Enemy.h"
#include "InGameEvent.h"
#include "Paths.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void InitializeGame();
	void MainMenu();

	void CreateNewCharacter();
	void Save();
	void Load(std::string& filePath);
	void Travel();

	inline bool IsPlaying() const { return this->isPlaying; }

private:
	int choice;
	bool isPlaying;

	Character character;
	InGameEvent inGameEvent;

	dArray<Enemy> enemies;
};

