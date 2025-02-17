#include "Character.h"
#include "Inventory.h"

std::map<Character::Stat, int> stats;

Character::Character()
{
	this->distanceTravelled = 0;

	this->name = "";
	this->level = 0;
	this->gold = 0;

	stats = std::map<Stat, int>();
	stats[Stat::STRENGTH] = 0;
	stats[Stat::VITALITY] = 0;
	stats[Stat::DEXTERITY] = 0;
	stats[Stat::INTELLIGENCE] = 0;

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
	stats[Stat::STRENGTH] = std::stoi(sheet[7]);
	stats[Stat::VITALITY] = std::stoi(sheet[8]);
	stats[Stat::DEXTERITY] = std::stoi(sheet[9]);
	stats[Stat::INTELLIGENCE] = std::stoi(sheet[10]);

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

	stats[Stat::STRENGTH] = 5;
	stats[Stat::DEXTERITY] = 5;
	stats[Stat::VITALITY] = 5;
	stats[Stat::INTELLIGENCE] = 5;

	UpdateStats();

	this->hp = this->maxHp;
	this->stamina = this->maxStamina;
	this->exp = 0;
}

void Character::UpdateStats()
{
	this->maxHp = (stats[Stat::VITALITY] * 2) + static_cast<int>(stats[Stat::STRENGTH] * 0.5);
	this->maxDamage = stats[Stat::STRENGTH] * 2;
	this->minDamage = stats[Stat::STRENGTH];
	this->defence = stats[Stat::DEXTERITY] + static_cast<int>(stats[Stat::INTELLIGENCE] * 0.5);
	this->maxStamina = stats[Stat::VITALITY] + static_cast<int>(stats[Stat::STRENGTH] * 0.5) + static_cast<int>(stats[Stat::DEXTERITY] * 0.33);
	this->accuracy = stats[Stat::DEXTERITY] * 0.5;
	this->luck = stats[Stat::INTELLIGENCE];
	this->nextExp = GetNextExpFor(level);
}

int Character::GetNextExpFor(const int level)
{
	return static_cast<int>(50 / 3)
		* static_cast<int>((pow(level, 3))
			- 6 * pow(level, 2)
			+ (17 * level - 12)) + 100;
}

std::string Character::GetAsString()
{
	return Utils::Concat({
		this->name,
		std::to_string(this->hp),
		std::to_string(this->level),
		std::to_string(this->exp),
		std::to_string(this->gold),
		std::to_string(this->distanceTravelled),
		std::to_string(this->stamina),
		std::to_string(stats[Stat::STRENGTH]),
		std::to_string(stats[Stat::VITALITY]),
		std::to_string(stats[Stat::DEXTERITY]),
		std::to_string(stats[Stat::INTELLIGENCE]),
		" "
		});
}

void Character::PrintAllStats() const
{
	Utils::Printn("===== STATS =====");
	Utils::Print({ "Name: ", this->name });
	Utils::Print({ "HP: ", std::to_string(this->hp), " / ", std::to_string(this->maxHp) });
	Utils::Print({ "Level: ", std::to_string(this->level) });
}

void Character::IterateStats() const
{
	Utils::Break();
	for (auto const& [stat, val] : stats)
	{
		int index = static_cast<int>(stat) + 1;
		Utils::Print(std::to_string(index) + ". " + this->statNames.at(stat) + ": " + std::to_string(val));
	}
}

void Character::LevelUp()
{
	int levelUpCount = 0;
	while (this->exp >= this->nextExp)
	{
		levelUpCount++;
		this->exp -= this->nextExp;
		this->level++;

		IterateStats();
		int statToIncreasae = Utils::GetInputInt("Increase stat:", 1, static_cast<int>(stats.size()));

		Stat stat = static_cast<Stat>(statToIncreasae - 1);
		AddToStat(stat);
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

		PrintAllStats();
	}
}

void Character::AddExp(const int& exp)
{
	this->exp += exp;
	LevelUp();
	Utils::Print("+ " + std::to_string(exp) + " exp. (" + std::to_string(this->exp) + " / " + std::to_string(this->nextExp) + ")");
}

void Character::AddToStat(const Stat& stat, const int& value)
{
	stats[stat] += value;
}


