#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>

class Span
{
	private:
		std::vector<int>	container;
		unsigned int 		size;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &span);
		Span &operator = (const Span &span);
		~Span();

		void			addNumber(int const newNumber);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
};

#endif