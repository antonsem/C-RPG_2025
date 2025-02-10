#pragma once

#include "Character.h"
#include "Puzzle.h"

class InGameEvent
{
public:
	InGameEvent();
	virtual ~InGameEvent();

	void GenerateEvent(Character& character);

private:

	int numberOfEvents;

	void EnemyEncounter(Character& character);
	void PuzzleEncounter(Character& character);
};

