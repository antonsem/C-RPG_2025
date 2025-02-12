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
	Puzzle puzzle("TestPuzzle.txt");
	int playerAnswer = -1;
	int attemptsLeft = puzzle.GetMaxAttemptCount();

	while (attemptsLeft > 0)
	{
		Utils::Print('\n' + puzzle.GetAsString());
		Utils::Print("Your answer: ", 0);

		std::cin >> playerAnswer;

		if (playerAnswer != puzzle.GetCorrectAnswer())
		{
			attemptsLeft--;
			Utils::Print({
				"Nope.",
				std::to_string(attemptsLeft),
				" attempts left."
				});

			if (attemptsLeft > 0)
			{
				Utils::Print("Try again...");
			}
		}
		else
		{
			Utils::Print("That's right! Congratulations!");
			break;
		}
	}
}
