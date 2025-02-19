#pragma once

#include "Character.h"
#include "Puzzle.h"
#include "dArray.h"
#include "Enemy.h"

class InGameEvent
{
public:
	InGameEvent();
	virtual ~InGameEvent();

	void GenerateEvent(Character& character, dArray<Enemy>& enemies);

private:

	int numberOfEvents;

	void EnemyEncounter(Character& character, dArray<Enemy>& enemies);
	void PuzzleEncounter(Character& character);
};

