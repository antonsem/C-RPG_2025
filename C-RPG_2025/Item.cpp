#pragma once

#include "Item.h"

Item::Item(std::string name, int level, int rarity, int buyValue, int sellValue)
{
	this->name = name;
	this->level = level;
	this->rarity = rarity;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
}

Item::~Item()
{
}

const void Item::ToString()
{
	Utils::Print({
		"Name: " + this->name,
		"Level: " + std::to_string(this->level),
		"Rarity: " + std::to_string(this->rarity),
		"Buy Value: " + std::to_string(this->buyValue),
		"Sell Value:" + std::to_string(this->sellValue)
		});
}
