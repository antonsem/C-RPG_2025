#include "Utils.h"

void Utils::Print(const std::string output, const int newLineCount)
{
	std::cout << output;

	for (size_t i = 0; i < newLineCount; i++)
	{
		std::cout << std::endl;
	}
}
