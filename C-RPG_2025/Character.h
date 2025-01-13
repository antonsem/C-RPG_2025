#pragma once

#include <string>

class Character
{
public:
	Character();
	virtual ~Character();

	void Initialize(std::string name, int level);

	inline std::string& Name() const { this->name; }
	inline int& Level() const { this->level; }
	inline int& PosX() const { this->posX; }
	inline int& PosY() const { this->posY; }
	inline int& Hp() const { this->hp; }
	inline int& MaxHp() const { this->maxHp; }
	inline int& MinDamage() const { this->minDamage; }
	inline int& MaxDamage() const { this->maxDamage; }
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
	int stamina;
	int exp;
	int nextExp;
};

