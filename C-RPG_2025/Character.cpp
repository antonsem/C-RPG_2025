#include "Character.h"

Character::Character()
{
	this->name = "";
	this->level = 0;
	this->posX = 0;
	this->posY = 0;
	this->hp = 0;
	this->maxHp = 0;
	this->minDamage = 0;
	this->maxDamage = 0;
	this->stamina = 0;
	this->exp = 0;
	this->nextExp = 0;
}

Character::~Character()
{
}

void Character::Initialize(std::string name, int level)
{
	this->name = name;
	this->level = level;
	this->posX = 0;
	this->posY = 0;
	this->hp = 10;
	this->maxHp = 10;
	this->minDamage = 2;
	this->maxDamage = 5;
	this->stamina = 5;
	this->exp = 0;
	this->nextExp = 10;
}
