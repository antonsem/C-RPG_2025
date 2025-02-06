#pragma once

#include <fstream>
#include "Character.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void InitializeGame();
	void MainMenu();

	void CreateNewCharacter();
	void Save();
	void Load();
	void Travel();

	inline bool IsPlaying() const { return this->isPlaying; }

private:
	int choice;
	bool isPlaying;

	Character character;
};

