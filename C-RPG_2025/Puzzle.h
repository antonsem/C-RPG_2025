#pragma once

#include <fstream>
#include <iostream>

#include "Utils.h"

class Puzzle
{
public:
	Puzzle(const std::string fileName);
	virtual ~Puzzle();

	inline const int& GetCorrectAnswer() const { return this->correctAnswer; }
	inline const int& GetMaxAttemptCount() const { return this->maxAttempts; }

	std::string GetAsString();
	std::string DebugPrint();

private:
	std::string question;
	std::vector<std::string> answers;

	int maxAttempts;
	int correctAnswer;
};

