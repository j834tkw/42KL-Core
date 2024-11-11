#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <ctime>
#include <sys/time.h>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int>	og;
		std::vector<int>	vec;
		std::list<int>		lst;
		bool				has_extra;
		struct timeval		time_taken_vec;
		struct timeval		time_taken_lst;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator = (const PmergeMe &obj);
		~PmergeMe();

		const std::vector<int>	&getOg(void);
		const std::vector<int>	&getVec(void);
		const std::list<int>	&getLst(void);
		const bool				&getHasExtra(void);
		const struct timeval	&getTimeTakenVec(void);
		const struct timeval	&getTimeTakenLst(void);

		void initFromCharArr(int argc, char **argv);
		int jacobsthal(int n);
		void runFordJohnsons(void);

		std::vector<std::pair<int, int> > mergeSortPairsVector(std::vector<std::pair<int, int> > pairs);
		std::vector<std::pair<int, int> > mergePairsVector(std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right);
		void fordJohnsonVector(void);

		std::list<std::pair<int, int> > mergeSortPairsList(std::list<std::pair<int, int> > pairs);
		std::list<std::pair<int, int> > mergePairsList(std::list<std::pair<int, int> > left, std::list<std::pair<int, int> > right);
		void fordJohnsonList(void);

		class NonDigitFoundException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("There is a non-digit in the given arguments!");
				}
		};
};

std::ostream &operator << (std::ostream &outs, std::vector<int> vec);
std::ostream &operator << (std::ostream &outs, std::list<int> lst);

// std::list uses a linked list, therefore it has no random access, unlike std::vector

/*
	Vector uses RandomAccessIterator while list uses BidirectionalIterator.
	This caused a number of limitations, notably:
		- Vector has vector.at(index), while list doesn't
		- Vector can use iterator += , but list cannot
		- Vector can use *(iterator + 1), but list cannot
	The code has been changed such that vector and list both uses the same code, the only difference is vector/list
*/

#endif