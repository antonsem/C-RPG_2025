#include "Puzzle.h"

Puzzle::Puzzle(const std::string fileName)
{
	if (fileName.size() <= 0)
	{
		Utils::Print({
			"=*=*=*= ERROR =*=*=*=",
			"Can't load a puzzle! A file name is empty..."
			}, true);
		return;
	}

	std::ifstream inFile(fileName);

	int answerCount = 0;
	std::string answer = "";

	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> answerCount;
		inFile.ignore();

		for (size_t i = 0; i < answerCount; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}

		inFile >> this->correctAnswer;
		inFile.ignore();
	}
	else
	{
		throw("Couldn't open the puzzle " + fileName);
	}

	inFile.close();
}

Puzzle::~Puzzle()
{
}

std::string Puzzle::GetAsString()
{
	std::string question = Utils::Concat({
		"===== PUZZLE ME THIS =====",
		this->question
		}, '\n');

	std::string answers = Utils::Concat(this->answers, '\n');
	return question + '\n' + answers;
}
