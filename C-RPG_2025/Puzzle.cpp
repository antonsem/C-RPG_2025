#include "Puzzle.h"
#include "Paths.h"

Puzzle::Puzzle(const std::string fileName)
{
	this->question = "";
	this->answers = std::vector<std::string>();
	this->maxAttempts = -1;
	this->correctAnswer = -1;
	this->experienceReward = 0;

	if (fileName.size() <= 0)
	{
		Utils::Print({
			"=*=*=*= ERROR =*=*=*=",
			"Can't load a puzzle! A file name is empty..."
			}, true);
		return;
	}

	std::ifstream inFile(Paths::PUZZLE_PATH + fileName);

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

		inFile >> this->maxAttempts;
		inFile.ignore();
		inFile >> this->correctAnswer;
		inFile.ignore();
		inFile >> this->experienceReward;
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
	return Utils::Concat({ question, answers }, '\n');
}

std::string Puzzle::DebugPrint()
{
	std::string question = Utils::Concat({
		"***** DEBUG PUZZLE *****",
		this->question
		}, '\n');

	std::string answers = Utils::Concat(this->answers, '\n');
	return Utils::Concat({ question, answers, std::to_string(this->maxAttempts),  std::to_string(this->correctAnswer), std::to_string(experienceReward)}, '\n');
}
