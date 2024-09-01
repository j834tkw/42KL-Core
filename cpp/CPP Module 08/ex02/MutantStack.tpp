#include "MutantStack.hpp"

using std::cout;
using std::endl;

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other) : std::stack<T>(other)
{}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other)
{
	if (this == &other)
		return (*this);
	this->c = other.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	// c refers to the underlying container object, whether it is an array, linked list or etc
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}
