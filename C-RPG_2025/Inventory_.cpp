#pragma once

#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 4;
	this->itemCount = 0;
	this->items = new Item * [capacity];
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
}

void Inventory::Initialize(const int from = 0)
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
		temp[i] = new Item(*this->items[i]);
	}

	for (size_t i = 0; i < itemCount; i++)
	{
		delete this->items[i];
	}

	delete[] this->items;

	this->items = temp;

	Initialize(itemCount);
}

void Inventory::RemoveItem(int index)
{
}

