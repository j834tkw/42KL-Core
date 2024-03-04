#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

class ValueNotFoundException : public std::exception
{
	const char * what(void) const throw()
	{
		return ("Smh cant even find smth from such a simple container?? *prolly gonna give you up-*");
	}
};

// An iterator is an object that points to an element inside the container (like a pointer). It is used to move through the contents of the container
template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	//	typename is used for specifying that a dependent name in a template definition or declaration is a type
	//	A dependent name is a name that depends on the type or the value of a template parameter
	typename T::iterator iter;

	//	std::find (initial position, final position + 1, value to find)
	iter = std::find(container.begin(), container.end(), value);

	//	if value is found, its position is returned, if not then the last position is returned
	if (iter == container.end()) 
		throw (ValueNotFoundException());

	return (iter);
}

#endif