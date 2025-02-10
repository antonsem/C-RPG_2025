#pragma once

#include <fstream>
#include <iostream>

#include "Utils.h"

class Puzzle
{
public:
	Puzzle(const std::string fileName);
	virtual ~Puzzle();

	std::string GetAsString();

private:
	std::string question;
	std::vector<std::string> answers;

	int correctAnswer;
};

