#include "Utils.h"

void Utils::Break(const int count)
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << std::endl;
	}
}

void Utils::Print(const std::string output, const int newLineCount)
{
	std::cout << output;

	for (size_t i = 0; i < newLineCount; i++)
	{
		std::cout << std::endl;
	}
}

void Utils::Print(const std::vector<std::string> output, const bool eachNewLine, const int newLineCount)
{
	int size = static_cast<int>(output.size());
	for (size_t i = 0; i < size; i++)
	{
		std::cout << output[i];
		if (eachNewLine)
		{
			std::cout << std::endl;
		}
	}

	for (size_t i = 0; i < newLineCount; i++)
	{
		std::cout << std::endl;
	}
}

std::string Utils::Concat(const std::vector<std::string> output, const char separator)
{
	std::string retVal;
	int size = static_cast<int>(output.size());
	for (size_t i = 0; i < size; i++)
	{
		retVal += output[i] + separator;
	}

	return retVal;
}

std::string Utils::GetInput(const std::string question)
{
	Print({ question, ": " }, false, 0);
	std::string retVal;
	std::getline(std::cin, retVal);
	return retVal;
}
