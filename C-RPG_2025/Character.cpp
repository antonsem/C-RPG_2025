#include "Character.h"

Character::Character()
{
	this->posX = 0;
	this->posY = 0;

	this->name = "";
	this->level = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->maxHp = 0;
	this->minDamage = 0;
	this->maxDamage = 0;
	this->defence = 0;
	this->stamina = 0;
	this->exp = 0;
	this->nextExp = 0;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::~Character()
{
}

void Character::Initialize(const std::string name, int level)
{
	this->posX = 0;
	this->posY = 0;

	this->name = name;
	this->level = level;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->hp = 10;
	this->maxHp = 10;
	this->minDamage = 2;
	this->maxDamage = 5;
	this->defence = 1;
	this->stamina = 5;
	this->exp = 0;
	this->nextExp = GetNextExpFor(level);

	this->statPoints = 5;
	this->skillPoints = 5;
}

int Character::GetNextExpFor(const int level)
{
	return static_cast<int>(50 / 3)
		* static_cast<int>((pow(level, 3))
			- 6 * pow(level, 2)
			+ (17 * level - 12)) + 100;
}

void Character::PrintStats() const
{
	Utils::Break();
	Utils::Print("===== STATS =====");
	Utils::Print({ "Name: ", this->name });
	Utils::Print({ "HP: ", std::to_string(this->hp), " / ", std::to_string(this->maxHp) });
}

void Character::LevelUp()
{
	while (this->exp > this->nextExp)
	{
		this->exp -= this->nextExp;
		this->level++;
		this->nextExp = GetNextExpFor(this->level);

		this->statPoints++;
		this->skillPoints++;
	}
}
