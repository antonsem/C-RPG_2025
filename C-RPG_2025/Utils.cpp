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
	int size = output.size();
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
