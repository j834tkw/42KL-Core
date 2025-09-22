#include "Span.hpp"

int main()
{
	std::vector<int>	veccie;
	for (int i = 0; i < 5; i++)
	{
		veccie.push_back(i);
	}

	Span sp = Span(5);
	sp.addNumber(veccie);
	try
	{
		sp.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "1a. " << sp.shortestSpan() << std::endl;
	std::cout << "1b. " << sp.longestSpan() << std::endl;
	// return 0;

	Span sp2 = Span(11000);
	for (int i = 0; i < 10998; i++)
		sp2.addNumber(i);
	sp2.addNumber(-10000);
	sp2.addNumber(25000);
	std::cout << "2a. " << sp2.shortestSpan() << std::endl;
	std::cout << "2b. " << sp2.longestSpan() << std::endl;
	return 0;
}