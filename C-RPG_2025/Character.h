#pragma once

#include <string>
#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	void Initialize(const std::string name, int level);
	void PrintStats() const;
	void LevelUp();
	int GetNextExpFor(const int level);

	inline std::string& Name() const { this->name; }
	inline int& Level() const { this->level; }
	inline int& PosX() const { this->posX; }
	inline int& PosY() const { this->posY; }
	inline int& Hp() const { this->hp; }
	inline int& MaxHp() const { this->maxHp; }
	inline int& MinDamage() const { this->minDamage; }
	inline int& MaxDamage() const { this->maxDamage; }
	inline int& Defence() const { this->defence; }
	inline int& Stamina() const { this->stamina; }
	inline int& Exp() const { this->exp; }
	inline int& NextExp() const { this->nextExp; }

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
	int stamina;
	int exp;
	int nextExp;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int statPoints;
	int skillPoints;
};

