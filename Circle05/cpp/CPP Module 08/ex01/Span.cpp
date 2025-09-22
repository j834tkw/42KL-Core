#include "Span.hpp"

using std::cout;
using std::endl;
using std::string;

Span::Span()
{
}

Span::Span(Span const &obj)
{
	*this = obj;
}

Span::Span(unsigned int n)
{
	this->maxSize = n;
}

Span::~Span()
{
}

Span &Span::operator = (const Span &span)
{
	if (this == &span)
		return (*this);
	this->container = span.container;
	this->maxSize = span.maxSize;
	return (*this);
}

void	Span::addNumber(int const newNumber)
{
	if (container.size() >= maxSize)
	{
		throw std::out_of_range("Max number of elements reached");
	}
	container.push_back(newNumber);
}

void	Span::addNumber(std::vector<int> newNumber)
{
	if (container.size() + newNumber.size() > maxSize)
	{
		throw std::out_of_range("Max number of elements reached");
	}
	for (std::vector<int>::iterator it = newNumber.begin(); it != newNumber.end(); it++)
		container.push_back(*it);
}

unsigned int Span::longestSpan(void)
{
	if (container.size() < 2)
	{
		throw std::out_of_range("List too small");
	}
	// max_element returns the element found with the largest value, and min_element does so for the smallest value
	// subtracting them gives us the difference between the largest and smallest value
	return (*std::max_element(container.begin(), container.end()) - *std::min_element(container.begin(), container.end()));
}

unsigned int	Span::shortestSpan(void)
{
	if (container.size() < 2)
	{
		throw std::out_of_range("List too small");
	}

	// numeric limits is a template that accepts a data type and returns a value based on the called function
	// it provides a standardized way to get information/properties for data types
	// here, ::max() returns the maximum possible value for unsigned it, which is 4294967295
	unsigned int difference = std::numeric_limits<unsigned int>::max();

	/**
	 * EXAMPLE
	 * In an array [1, 3, 4, 7] during the 1st outer loop iteration, its outer iteration points to 1, then the inner iteration points to 3
	 * Difference between 1 and 3 is 2, since it's smaller than 4294967295, it saves 2
	 * 1 is then compared to 4 and 7.
	 * During the 2nd outer loop iteration, 3 is pointed to, and then compared to 4 and 7
	 * This continues until it loops array size - 1 times, and the smallest value recorded is returned
	 */
	for (std::vector<int>::iterator iter_a = container.begin(); iter_a < container.end() - 1; iter_a++)
		for (std::vector<int>::iterator iter_b = iter_a + 1; iter_b < container.end(); iter_b++)
		{
			unsigned int tmp = abs((*iter_a) - (*iter_b));
			if (tmp < difference)
				difference = tmp;
		}
	return (difference);
}
