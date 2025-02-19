#pragma once


template<typename T>
class dArray
{
private:
	unsigned capacity;
	unsigned initialCapacity;
	unsigned itemCount;
	T** array;

	void Expand();
	void Initialize(const int from);
	void DeleteAllElements();
	void Clone(const dArray& obj);

public:
	dArray(unsigned size = 4);
	dArray(const dArray& obj);
	~dArray();

	T& operator[](const unsigned index);
	void operator=(const dArray& obj);

	unsigned Capacity();
	unsigned Size();
	void Push(const T obj);
	void Remove(const unsigned index, bool ordered = false);
};
#include <iostream>

template<typename T>
dArray<T>::dArray(unsigned size)
{
	this->initialCapacity = size;
	this->capacity = size;
	this->itemCount = 0;

	this->array = new T * [this->capacity];

	Initialize(0);
}

template<typename T>
dArray<T>::dArray(const dArray& obj)
{
	Clone(obj);
}

template<typename T>
dArray<T>::~dArray()
{
	DeleteAllElements();
}

template<typename T>
void dArray<T>::Expand()
{
	this->capacity *= 2;

	T** temp = new T * [this->capacity];

	for (size_t i = 0; i < this->itemCount; i++)
	{
		temp[i] = this->array[i];
	}

	delete[] array;

	this->array = temp;
	Initialize(this->itemCount);
}

template<typename T>
void dArray<T>::Initialize(const int from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->array[i] = nullptr;
	}
}

template<typename T>
void dArray<T>::DeleteAllElements()
{
	for (size_t i = 0; i < this->itemCount; i++)
	{
		delete array[i];
	}
	delete[] array;
}

template<typename T>
void dArray<T>::Clone(const dArray& obj)
{
	this->initialCapacity = obj.initialCapacity;
	this->capacity = obj.capacity;
	this->itemCount = obj.itemCount;

	this->array = new T * [this->capacity];

	for (size_t i = 0; i < this->itemCount; i++)
	{
		this->array[i] = new T(*obj.array[i]);
	}

	Initialize(this->itemCount);
}

template<typename T>
T& dArray<T>::operator[](const unsigned index)
{
	if (index < 0 || index >= itemCount)
	{
		throw "INDEX IS OUT OF BOUNDDS EXCEPTION";
	}

	return *this->array[index];
}

template<typename T>
void dArray<T>::operator=(const dArray& obj)
{
	DeleteAllElements();
	Clone(obj);
}

template<typename T>
unsigned dArray<T>::Capacity()
{
	return this->capacity;
}

template<typename T>
unsigned dArray<T>::Size()
{
	return this->itemCount;
}

template<typename T>
void dArray<T>::Push(const T obj)
{
	if (this->itemCount >= this->capacity)
	{
		Expand();
	}

	this->array[this->itemCount++] = new T(obj);
}

template<typename T>
void dArray<T>::Remove(const unsigned index, bool ordered)
{
	if (index < 0 || index >= this->itemCount)
	{
		throw "INDEX OUT OF BOUNDS EXCEPTION!";
	}

	std::cout << "\nRemoving " << this->operator[](index) << '\n';

	delete this->array[index];

	if (ordered)
	{
		for (size_t i = index; i < this->itemCount - 1; i++)
		{
			array[i] = array[i + 1];
		}
	}
	else
	{
		array[index] = array[itemCount - 1];
	}

	this->array[this->itemCount - 1] = nullptr;
	this->itemCount--;
}