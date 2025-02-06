#include "Weapon.h"

Weapon::Weapon(int minDamage, int maxDamage, std::string name, int level, int rarity, int buyValue, int sellValue)
	: Item(name, level, rarity, buyValue, sellValue)
{
	this->minDamage = minDamage;
	this->maxDamage = maxDamage;
}

Weapon::~Weapon()
{
}

const void Weapon::ToString()
{
	Utils::Print({
		"Minimum Damage: " + std::to_string(this->minDamage),
		"Maximum Damage: " + std::to_string(this->maxDamage)
		});
}

Weapon* Weapon::Clone() const
{
	return new Weapon(*this);
}
