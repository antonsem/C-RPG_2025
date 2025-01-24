#pragma once

#include <string>
#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	void Initialize(const std::string name, int level = 0);
	void PrintStats() const;
	void LevelUp();
	int GetNextExpFor(const int level);
	std::string GetAsString() const;

	inline const std::string& Name() const { return this->name; }
	inline const int& Level() const { return this->level; }
	inline const int& PosX() const { return this->posX; }
	inline const int& PosY() const { return this->posY; }
	inline const int& Hp() const { return this->hp; }
	inline const int& MaxHp() const { return this->maxHp; }
	inline const int& MinDamage() const { return this->minDamage; }
	inline const int& MaxDamage() const { return this->maxDamage; }
	inline const int& Defence() const { return this->defence; }
	inline const int& Stamina() const { return this->stamina; }
	inline const int& Exp() const { return this->exp; }
	inline const int& NextExp() const { return this->nextExp; }

private:
	std::string name;
	int level;
	int posX;
	int posY;
	int hp;
	int maxHp;
	int minDamage;
	int maxDamage;
	int defence;
	int maxStamina;
	int stamina;
	int luck;
	int exp;
	int nextExp;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int statPoints;
	int skillPoints;
};

