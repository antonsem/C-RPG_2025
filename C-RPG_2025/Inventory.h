#pragma once

#include "Item.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	void AddItem(const Item& item);

	inline void DebugPrint() const
	{
		for (size_t i = 0; i < this->itemCount; i++)
		{
			this->items[i]->DebugPrint();
		}
	}

private:
	int capacity;
	int itemCount;
	Item** items;

	void Initialize(const int from = 0);
	void Expand();
	void RemoveItem(int index);

};