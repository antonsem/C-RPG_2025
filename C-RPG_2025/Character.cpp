#include "Character.h"
#include "Inventory.h"

Character::Character()
{
	this->posX = 0;
	this->posY = 0;
	this->distanceTravelled = 0;

	this->name = "";
	this->level = 0;
	this->gold = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->maxHp = 0;
	this->minDamage = 0;
	this->maxDamage = 0;
	this->defence = 0;
	this->maxStamina = 0;
	this->stamina = 0;
	this->accuracy = 0;
	this->luck = 0;
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
	this->distanceTravelled = 0;

	this->name = name;
	this->level = level;

	this->gold = 100;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->maxHp = (this->vitality * 2) + static_cast<int>(this->strength * 0.5);
	this->hp = this->maxHp;
	this->maxDamage = this->strength * 2;
	this->minDamage = this->strength;
	this->defence = this->dexterity + static_cast<int>(this->intelligence * 0.5);
	this->maxStamina = this->vitality + static_cast<int>(this->strength * 0.5) + static_cast<int>(this->dexterity * 0.33);
	this->stamina = this->maxStamina;
	this->accuracy = this->dexterity * 0.5;
	this->luck = intelligence;
	this->exp = 0;
	this->nextExp = GetNextExpFor(level);

	this->statPoints = 5;
	this->skillPoints = 5;

	inventory.AddItem(Weapon(5, 10, "Hidden Dagger"));
	inventory.AddItem(Armor(0, 1, "Robe"));
}

int Character::GetNextExpFor(const int level)
{
	return static_cast<int>(50 / 3)
		* static_cast<int>((pow(level, 3))
			- 6 * pow(level, 2)
			+ (17 * level - 12)) + 100;
}

std::string Character::GetAsString() const
{
	return Utils::Concat({
		this->name,
		std::to_string(this->level),
		std::to_string(this->posX),
		std::to_string(this->posY),
		std::to_string(this->strength),
		std::to_string(this->vitality),
		std::to_string(this->dexterity),
		std::to_string(this->intelligence),
		});
}

void Character::PrintStats() const
{
	Utils::Break();
	Utils::Print("\n===== STATS =====");
	Utils::Print({ "Name: ", this->name });
	Utils::Print({ "HP: ", std::to_string(this->hp), " / ", std::to_string(this->maxHp) });
}

void Character::LevelUp()
{
	int levelUpCount = 0;
	while (this->exp > this->nextExp)
	{
		levelUpCount++;
		this->exp -= this->nextExp;
		this->level++;
		this->nextExp = GetNextExpFor(this->level);

		this->statPoints++;
		this->skillPoints++;
	}

	if (levelUpCount > 0)
	{
		if (levelUpCount == 1)
		{
			Utils::Print("+ " + std::to_string(levelUpCount) + " level");
		}
		else
		{
			Utils::Print("+ " + std::to_string(levelUpCount) + " levels");
		}

		PrintStats();
	}
}

void Character::AddExp(const int& exp)
{
	this->exp += exp;
	LevelUp();
	Utils::Print("+ " + std::to_string(exp) + " exp. (" + std::to_string(this->exp) + " / " + std::to_string(this->nextExp) + ")");
}
