#pragma once

#include <string>
#include <map>
#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	enum Stat {
		STRENGTH = 0,
		VITALITY = 1,
		DEXTERITY = 2,
		INTELLIGENCE = 3
	};

	void Initialize(const std::string& name, int level = 0);
	void InitializeFromFile(std::string& str);
	void PrintAllStats() const;
	void IterateStats() const;
	inline void PrintInventory() const { this->inventory.DebugPrint(); }
	void LevelUp();
	void AddExp(const int& exp);
	void AddToStat(const Stat& stat, const int& value = 1);
	void UpdateStats();
	int GetNextExpFor(const int level);
	std::string GetAsString();

	inline const std::string& Name() const { return this->name; }
	inline const int& Level() const { return this->level; }
	inline const int& Hp() const { return this->hp; }
	inline const int& MaxHp() const { return this->maxHp; }
	inline const int& MinDamage() const { return this->minDamage; }
	inline const int& MaxDamage() const { return this->maxDamage; }
	inline const int& Defence() const { return this->defence; }
	inline const int& Stamina() const { return this->stamina; }
	inline const int& Exp() const { return this->exp; }
	inline const int& NextExp() const { return this->nextExp; }

	inline void AddDistanceTravelled(const int& distance = 1) { this->distanceTravelled += distance; }

private:
	std::string name;

	Inventory inventory;
	Weapon weapon;
	Armor armor;
	int gold;

	int level;
	int distanceTravelled;
	int hp;
	int maxHp;
	int minDamage;
	int maxDamage;
	int defence;
	int maxStamina;
	int stamina;
	int luck;
	int accuracy;
	int exp;
	int nextExp;

	const std::map<Stat, std::string> statNames = {
		{Stat::STRENGTH, "Strenght"},
		{Stat::VITALITY, "Vitality"},
		{Stat::DEXTERITY, "Dexterity"},
		{Stat::INTELLIGENCE, "Intelligence"},
	};
};

