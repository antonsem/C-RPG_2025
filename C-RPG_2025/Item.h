#pragma once

#include "Utils.h"

class Item
{
public:
	Item();
	virtual ~Item();

	inline void DebugPrint() const { Utils::Print(name); }

private:
	std::string name;
	int buyValue;
	int sellValue;
};
