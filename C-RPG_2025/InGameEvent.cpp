#include "InGameEvent.h"

InGameEvent::InGameEvent()
{
	this->numberOfEvents = 2;
}

InGameEvent::~InGameEvent()
{
}

void InGameEvent::GenerateEvent(Character& character)
{
	int eventNumber = rand() % this->numberOfEvents;

	switch (eventNumber)
	{
	case 0:
		EnemyEncounter(character);
		break;
	case 1:
		PuzzleEncounter(character);
		break;
	default:
		Utils::Print({
			"=*=*=*= ERROR =*=*=*=",
			"Trying to generate event number " + std::to_string(eventNumber) + ". Event count is " + std::to_string(this->numberOfEvents) + "!"
			}, true);
		break;
	}
}

void InGameEvent::EnemyEncounter(Character& character)
{
}

void InGameEvent::PuzzleEncounter(Character& character)
{
}
