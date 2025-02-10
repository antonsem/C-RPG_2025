#pragma once

#include <iostream>
#include <string>
#include <vector>

class Utils
{
public:
	static void Break(const int count = 1);
	static void Print(const std::string output, const int newLineCount = 1);
	static void Print(const std::vector<std::string> output, const bool eachNewLine = false, const int newLineCount = 1);
	static std::string Concat(const std::vector<std::string> output, const char separator = ' ');
	static std::string GetInput(const std::string question);
};