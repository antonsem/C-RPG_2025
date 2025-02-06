#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = hpMax;
	this->damageMin = this->level * 2;
	this->damageMax = this->level * 4;
	this->dropChance = rand() % 100;
	this->defence = rand() % 100;
	this->accuracy = rand() % 100;
}

Enemy::~Enemy()
{
}

std::string Enemy::GetAsString() const
{
	return Utils::Concat({
		"\n--- ENEMY ---",
		"Level: " + std::to_string(this->level),
		"HP: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax),
		"Damage: " + std::to_string(this->damageMin) + " - " + std::to_string(this->damageMax),
		"Drop chance: " + std::to_string(this->dropChance),
		"Defence: " + std::to_string(this->defence),
		"Accuracy: " + std::to_string(this->accuracy)
		}, '\n');
}
