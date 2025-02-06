#pragma once

#include <stdlib.h>
#include "Utils.h"

class Enemy
{
public:
	Enemy(int level = 0);
	virtual ~Enemy();

	inline bool IsAlive() const { return this->hp > 0; }

	inline void TakeDamage(int damage) { this->hp -= damage; }
	inline int GetDamage() const { return rand() % (this->damageMax - this->damageMin) + this->damageMin; }
	inline int GetExp() const { return this->level * 10; }
	std::string GetAsString() const;

private:
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	float dropChance;
	int defence;
	int accuracy;
};

