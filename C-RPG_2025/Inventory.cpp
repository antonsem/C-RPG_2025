#pragma once

#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 4;
	this->itemCount = 0;
	this->items = new Item * [capacity];
	this->Initialize();
}

Inventory::Inventory(const Inventory& obj)
{
	this->capacity = obj.capacity;
	this->itemCount = obj.itemCount;
	this->items = new Item * [this->capacity];

	for (size_t i = 0; i < this->itemCount; i++)
	{
		this->items[i] = obj.items[i]->Clone();
	}

	Initialize(this->itemCount);
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->itemCount; i++)
	{
		delete this->items[i];
	}

	delete this->items;
}

void Inventory::AddItem(const Item& item)
{
	if (this->itemCount >= this->capacity)
	{
		Expand();
	}

	this->items[this->itemCount++] = item.Clone();
}

Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->itemCount)
	{
		throw("BAD INDEX!");
	}

	return *this->items[index];
}

void Inventory::Initialize(const int from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->items[i] = nullptr;
	}
}

void Inventory::Expand()
{
	this->capacity *= 2;

	Item** temp = new Item * [this->capacity];

	for (size_t i = 0; i < this->itemCount; i++)
	{
		temp[i] = this->items[i];
	}

	delete[] this->items;

	this->items = temp;

	Initialize(itemCount);
}

void Inventory::RemoveItem(int index)
{
}

