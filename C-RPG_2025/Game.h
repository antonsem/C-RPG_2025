#pragma once

#include "Utils.h"
#include "Character.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void MainMenu();

	inline bool IsPlaying() const { return this->isPlaying; }

private:
	int choice;
	bool isPlaying;
};

