#pragma once

#include "Character.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void InitializeGame();
	void MainMenu();

	inline bool IsPlaying() const { return this->isPlaying; }

private:
	int choice;
	bool isPlaying;

	Character character;
};

