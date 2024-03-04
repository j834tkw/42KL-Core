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
}

Span::~Span()
{
}

unsigned int Span::longestSpan(void)
{
	if (size < 2)
	{
		throw std::out_of_range("List too small");
	}
	return (*std::max_element(container.begin(), container.end()) - *std::min_element(container.begin(), container.end()));
}

unsigned int	Span::shortestSpan(void)
{
	if (size < 2)
	{
		throw std::out_of_range("List too small");
	}
	std::sort(container.begin(), container.end());
	std::vector<int>::iterator iter = container.begin();
	for (iter; iter < container.end(); iter++)
	{
		
	}
}