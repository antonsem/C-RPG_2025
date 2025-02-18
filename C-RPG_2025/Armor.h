#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor(int type = 0, int defence = 0, std::string name = "NONE", int level = 0, int rarity = 0, int buyValue = 0, int sellValue = 0);
	virtual ~Armor();

	inline const int& GetDefence() const { return this->defence; }

	const void ToString();

	virtual Armor* Clone() const;

private:

	int type;
	int defence;
};

