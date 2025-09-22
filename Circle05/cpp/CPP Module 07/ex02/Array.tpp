#ifndef ARRAY_TPP // .tpp file is basically .cpp file but for templates
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= size())
		throw (OutOfBoundsException());
	return (array[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= size())
		throw (OutOfBoundsException());
	return (array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (arrSize); // removing this-> makes it usable as const func bru
}

//-------------------------------------------------------------------------------------------------------------------------------

template <typename T>
Array<T>::Array()
{
	cout << "[Array] Default constructor called" << endl;
	this->array = new T[0];
	this->arrSize = 0;
}

template <typename T>
Array<T>::Array(unsigned int newSize)
{
	cout << "[Array] Constructor called" << endl;
	this->array = new T[newSize];
	this->arrSize = newSize;
}

template <typename T>
Array<T>::Array(const Array &obj)
{
	cout << "[Array] Copy constructor called" << endl;
	*this = obj;
}

template <typename T>
Array<T> &Array<T>::operator= (const Array &obj)
{
	cout << "[Array] Copy assignment operator called" << endl;
	// if (this == &array)
	// 	return (*this);
	this->array = new T[obj.size()]; // size func needs to be const so compiler guarantees it will not change obj
	this->arrSize = obj.size();
	for (unsigned int i = 0; i < this->arrSize; i++)
		this->array[i] = obj.array[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	cout << "[Array] Destructor called" << endl;
	delete[] array;
}

#endif