#pragma once

#include "Weapon.h"
#include "Armor.h"

class Inventory
{
public:
	Inventory();
	Inventory(const Inventory& obj);
	virtual ~Inventory();

	void AddItem(const Item& item);

	inline int Size() const { return this->itemCount; }
	Item& operator[](const int index);

	inline void DebugPrint() const
	{
		Utils::Print("\n===== Inventory =====");
		for (size_t i = 0; i < this->itemCount; i++)
		{
			this->items[i]->DebugPrint();
		}
		Utils::Print("==========", 2);
	}

private:
	int capacity;
	int itemCount;
	Item** items;

	void Initialize(const int from = 0);
	void Expand();
	void RemoveItem(int index);

};