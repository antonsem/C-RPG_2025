#include "Character.h"
#include "Inventory.h"

Character::Character()
{
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
	this->inventory.Initialize();
}

void Character::InitializeFromFile(std::string& str)
{
	std::vector<std::string> sheet = std::vector<std::string>();

	size_t pos = 0;
	while ((pos = str.find(' ')) != std::string::npos)
	{
		sheet.push_back(str.substr(0, pos));
		str.erase(0, pos + 1);
	}

	this->name = sheet[0];
	this->hp = std::stoi(sheet[1]);
	this->level = std::stoi(sheet[2]);
	this->exp = std::stoi(sheet[3]);
	this->gold = std::stoi(sheet[4]);
	this->distanceTravelled = std::stoi(sheet[5]);
	this->stamina = std::stoi(sheet[6]);
	this->strength = std::stoi(sheet[7]);
	this->vitality = std::stoi(sheet[8]);
	this->dexterity = std::stoi(sheet[9]);
	this->intelligence = std::stoi(sheet[10]);
	this->skillPoints = std::stoi(sheet[11]);
	this->statPoints = std::stoi(sheet[12]);

	UpdateStats();
	this->inventory.Initialize();
}

Character::~Character()
{
}

void Character::Initialize(const std::string& name, int level)
{
	this->distanceTravelled = 0;

	this->name = name;
	this->level = level;

	this->gold = 100;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	UpdateStats();

	this->hp = this->maxHp;
	this->stamina = this->maxStamina;
	this->exp = 0;

	this->statPoints = 5;
	this->skillPoints = 5;
}

void Character::UpdateStats()
{
	this->maxHp = (this->vitality * 2) + static_cast<int>(this->strength * 0.5);
	this->maxDamage = this->strength * 2;
	this->minDamage = this->strength;
	this->defence = this->dexterity + static_cast<int>(this->intelligence * 0.5);
	this->maxStamina = this->vitality + static_cast<int>(this->strength * 0.5) + static_cast<int>(this->dexterity * 0.33);
	this->accuracy = this->dexterity * 0.5;
	this->luck = intelligence;
	this->nextExp = GetNextExpFor(level);
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
		std::to_string(this->hp),
		std::to_string(this->level),
		std::to_string(this->exp),
		std::to_string(this->gold),
		std::to_string(this->distanceTravelled),
		std::to_string(this->stamina),
		std::to_string(this->strength),
		std::to_string(this->vitality),
		std::to_string(this->dexterity),
		std::to_string(this->intelligence),
		std::to_string(this->skillPoints),
		std::to_string(this->statPoints),
		" "
		});
}

void Character::PrintStats() const
{
	Utils::Printn("===== STATS =====");
	Utils::Print({ "Name: ", this->name });
	Utils::Print({ "HP: ", std::to_string(this->hp), " / ", std::to_string(this->maxHp) });
	Utils::Print({ "Level: ", std::to_string(this->level) });
}

void Character::LevelUp()
{
	int levelUpCount = 0;
	while (this->exp >= this->nextExp)
	{
		levelUpCount++;
		this->exp -= this->nextExp;
		this->level++;

		this->statPoints++;
		this->skillPoints++;
	}

	if (levelUpCount > 0)
	{
		UpdateStats();
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


