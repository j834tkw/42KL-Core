#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string.h>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class Array {
	private:
		unsigned int arrSize;
		T 			*array;

	public:
		unsigned int size(void) const;
		T& operator[] (unsigned int index);
		const T& operator[] (unsigned int index) const; // for array & const array

		Array(void);
		Array(unsigned int newSize);
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		~Array(void);

		class OutOfBoundsException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("The given index is out of bounds");
			}
		};
};

#include "Array.tpp"

#endif