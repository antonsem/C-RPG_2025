#include "Armor.h"

Armor::Armor(int type, int defence, std::string name, int level, int rarity, int buyValue, int sellValue)
	: Item(name, level, rarity, buyValue, sellValue)
{
	this->type = type;
	this->defence = defence;
}

Armor::~Armor()
{
}

const void Armor::ToString()
{
	Utils::Print({ 
		"Type: " + std::to_string(this->type),
		"Defence: " + std::to_string(this->defence) });
}

Armor* Armor::Clone() const
{
	return new Armor(*this);
}
