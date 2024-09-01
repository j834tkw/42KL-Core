#include "PmergeMe.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::atoi;

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe	&PmergeMe::operator = (const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	// some stuff here
	return (*this);
}

PmergeMe::~PmergeMe()
{
}
