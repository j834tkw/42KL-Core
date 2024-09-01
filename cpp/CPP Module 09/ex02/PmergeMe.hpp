#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <list>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator = (const PmergeMe &obj);
		~PmergeMe();
};

#endif