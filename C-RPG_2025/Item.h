#pragma once

#include "Utils.h"

class Item
{
public:
	Item(std::string name = "NONE", int level = 0, int rarity = 0, int buyValue = 0, int sellValue = 0);
	virtual ~Item();

	inline void DebugPrint() const { Utils::Print(name); }

	inline const std::string& GetName() const { return this->name; }
	inline const int& GetLevel() const { return this->level; }
	inline const int& GetRarity() const { return this->rarity; }
	inline const int& GetBuyValue() const { return this->buyValue; }
	inline const int& GetSelValue() const { return this->sellValue; }

	const void ToString();

private:
	std::string name;
	int level;
	int rarity;
	int buyValue;
	int sellValue;
};
