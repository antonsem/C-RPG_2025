#pragma once

#include "Item.h"

class Weapon : public Item
{
public:

	Weapon(int damageMin = 0, int damageMax = 0, std::string name = "NONE", int level = 0, int rarity = 0, int buyValue = 0, int sellValue = 0);
	virtual ~Weapon();

	const void ToString();

	virtual Weapon* Clone() const;

private:

	int minDamage;
	int maxDamage;

};

