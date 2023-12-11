#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

// A template is allows us is to pass the data type as a parameter in a way that we don’t need to write the same code for different data types
// Usage of templates means one function can work for all data types
// This would work even for user defined types if, example in min, operator '<' is overloaded

// Templates can only be implemented in the header file
// Otherwise, potential compilation and linking problems will arise

template <typename t1> void swap(t1 &a, t1 &b)
{
	t1 temp = b;
	b = a;
	a = temp;
}

template <typename t1> t1 min(t1 &a, t1 &b)
{
	return ( a < b ? a : b );
}

template <typename t1> t1 max(t1 &a, t1 &b)
{
	return ( a > b ? a : b );
}

#endif