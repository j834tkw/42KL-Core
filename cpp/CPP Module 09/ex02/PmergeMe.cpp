#include "PmergeMe.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::cerr;
using std::atoi;

PmergeMe::PmergeMe()
{
	done_sorting = false;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe	&PmergeMe::operator = (const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	this->og = obj.og;
	this->vec = obj.vec;
	this->lst = obj.lst;
	this->has_extra = obj.has_extra;
	this->time_taken_vec = obj.time_taken_vec;
	this->time_taken_lst = obj.time_taken_lst;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

const vector<int>	&PmergeMe::getOg(void)
{
	return (og);
}

const vector<int>	&PmergeMe::getVec(void)
{
	return (vec);
}

const std::list<int>	&PmergeMe::getLst(void)
{
	return (lst);
}

const bool	&PmergeMe::getHasExtra(void)
{
	return (has_extra);
}

const double &PmergeMe::getTimeTakenVec(void)
{
	return (time_taken_vec);
}

const double &PmergeMe::getTimeTakenLst(void)
{
	return (time_taken_lst);
}

std::ostream &operator << (std::ostream &outs, vector<int> vec)
{
	vector<int>::iterator it = vec.begin();

	while (it != vec.end())
		outs << *it++ << " ";
	return (outs);
}

std::ostream &operator << (std::ostream &outs, std::list<int> lst)
{
	std::list<int>::iterator it = lst.begin();

	while (it != lst.end())
		outs << *it++ << " ";
	return (outs);
}

void PmergeMe::initFromCharArr(int argc, char **argv)
{
	std::string			str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		if (str.find_first_not_of("0123456789") == std::string::npos)
			og.push_back(std::atoi(argv[i]));
		else
			throw (NonDigitFoundException());
	}

	has_extra = false;
	if (og.size() % 2 == 1)
		has_extra = true;

	vector<int>::iterator begin = og.begin();
	vector<int>::iterator end = og.end();

	while (begin != end)
	{
		vec.push_back(*begin);
		lst.push_back(*begin);
		++begin;
	}

	done_sorting = false;
}

int	PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
}

bool PmergeMe::isVecSorted(void)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end() - 1; it++)
		if (*it > *(it + 1))
			return (false);
			
	return (true);
}

bool PmergeMe::isLstSorted(void)
{
	for (std::list<int>::const_iterator it = lst.begin(), next_it = ++lst.begin(); next_it != lst.end(); ++it, ++next_it)
        if (*it > *next_it)
            return (false);

    return (true);
}

void PmergeMe::runFordJohnsons(void)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	fordJohnsonVector();
	gettimeofday(&end, NULL);
	time_taken_vec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	fordJohnsonList();
	gettimeofday(&end, NULL);
	time_taken_lst = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	done_sorting = true;
}

void PmergeMe::printResults(void)
{
	if (done_sorting == false)
		throw (NotRunProperlyException());

	if (isVecSorted() == false || isLstSorted() == false)
		throw (NotSortedException());
	
	cout << "Before: " << og << endl;
	cout << "After (std::vector): " << vec << endl;
	cout << "After (std::list)  : " << lst << endl;
	cout << "Time to process a range of 5 elements with std::vector: " << time_taken_vec << " us" << endl;
	cout << "Time to process a range of 5 elements with std::list: " << time_taken_lst << " us" << endl;
}

/*	// =================================================================
	VECTORS
*/	// =================================================================

std::vector<std::pair<int, int> > PmergeMe::mergePairsVector(vector<std::pair<int, int> > left, vector<std::pair<int, int> > right)
{
	vector<std::pair<int, int> >::iterator	it_l = left.begin();
	vector<std::pair<int, int> >::iterator	it_r = right.begin();
	std::vector<std::pair<int, int> > ret;

	while (it_l != left.end() && it_r != right.end())
	{
		if ((*it_l).second < (*it_r).second)
		{
			ret.push_back(*it_l);
			++it_l;
		}
		else
		{
			ret.push_back(*it_r);
			++it_r;
		}
	}

	std::copy(it_l, left.end(), std::back_inserter(ret));
    std::copy(it_r, right.end(), std::back_inserter(ret));

	return ret;
}

std::vector<std::pair<int, int> > PmergeMe::mergeSortPairsVector(vector<std::pair<int, int> > pairs)
{
	if (pairs.size() <= 1)
		return pairs;
	
	vector<std::pair<int, int> >::iterator	mid = pairs.begin();
	std::advance(mid, pairs.size() / 2);

	vector<std::pair<int, int> > left = mergeSortPairsVector(std::vector<std::pair<int, int> >(pairs.begin(), mid));
	vector<std::pair<int, int> > right = mergeSortPairsVector(std::vector<std::pair<int, int> >(mid, pairs.end()));
	return mergePairsVector(left, right);
}

void	PmergeMe::fordJohnsonVector()
{
	/*
		If there is only 1 element, there is no need to sort
	*/
	if (vec.size() == 1)
		return ;

	/*
		Check if the number of elements is odd. If so, take the last number out
	*/
	int extra = 0;

	if (has_extra == true) 
	{
		extra = vec.back();
		vec.pop_back();
	}

	/*
		Now that we know there is an even number of elements, we split the numbers into pairs
		We also make sure that each pair is as follows: (smaller value, larger value)
	*/
	std::vector<std::pair<int, int> > pairs;
	std::pair<int, int>	pair;
	vector<int>::iterator it = vec.begin();
	int num_1;
	int num_2;

	while (it != vec.end())
	{
		num_1 = *it;
		++it;
		num_2 = *it;
		++it;
		if (num_1 < num_2)
			pair = std::pair<int, int>(num_1, num_2);
		else
			pair = std::pair<int, int>(num_2, num_1);
		pairs.push_back(pair);
	}

	/*
		Run the sorting algorithm
	*/
	pairs = mergeSortPairsVector(pairs);

	/*
		Place all second (larger) elements into main and all first (smaller) elements into pend
	*/
	vector<int> main;
	vector<int> pend;

	for (vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back((*it).second);
		pend.push_back((*it).first);
	}

	/*
		Since the 1st element in pend will always be smaller than the 1st element in main, 
		We can immediately move it into main
	*/
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	/*
		Creates a vector of integers that is sorted according to jacobsthal numbers
		E.g.	Jacobsthal numbers: 1 3 5 11
				Index of elements in pend to be inserted to tmp: [1] [3] 2 [5] 4 [11] 10 9 8 7 6
				* Note that in the actual index we need to -1
				So if we get a sequence of let's say [5, 2, 3, 1],
				We will get [5, 3, 2, 1]
	*/
	vector<int> tmp;
	int n = 1;
	int jacob = jacobsthal(n);
	vector<int>::iterator vector_it;

	while (true){
		if (tmp.size() == pend.size())
			break;
		else if (jacob == jacobsthal(n - 1))
		{
			n++;
			jacob = jacobsthal(n);
		}
		else
		{
			if (jacob > (int)pend.size())
				jacob = (int)pend.size();
			vector_it = pend.begin();
			std::advance(vector_it, jacob - 1); 
			tmp.push_back(*vector_it);
			jacob--;
		}
	}

	/*
		std::lower_bound performs a binary search
		We will use this to insert our elements in tmp, as well as the extra value to the correct positions
	*/
	for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
		main.insert(std::lower_bound(main.begin(), main.end(), *it), *it);
	if (has_extra == true)
		main.insert(std::lower_bound(main.begin(), main.end(), extra), extra);
	vec = main;

	return ;
}

/*	// =================================================================
	LISTS
*/	// =================================================================

std::list<std::pair<int, int> > PmergeMe::mergePairsList(list<std::pair<int, int> > left, list<std::pair<int, int> > right)
{
	list<std::pair<int, int> >::iterator	it_l = left.begin();
	list<std::pair<int, int> >::iterator	it_r = right.begin();
	std::list<std::pair<int, int> > ret;

	while (it_l != left.end() && it_r != right.end())
	{
		if ((*it_l).second < (*it_r).second)
		{
			ret.push_back(*it_l);
			++it_l;
		}
		else
		{
			ret.push_back(*it_r);
			++it_r;
		}
	}

	std::copy(it_l, left.end(), std::back_inserter(ret));
    std::copy(it_r, right.end(), std::back_inserter(ret));

	return ret;
}

std::list<std::pair<int, int> > PmergeMe::mergeSortPairsList(list<std::pair<int, int> > pairs)
{
	if (pairs.size() <= 1)
		return pairs;
	
	list<std::pair<int, int> >::iterator	mid = pairs.begin();
	std::advance(mid, pairs.size() / 2);

	list<std::pair<int, int> > left = mergeSortPairsList(std::list<std::pair<int, int> >(pairs.begin(), mid));
	list<std::pair<int, int> > right = mergeSortPairsList(std::list<std::pair<int, int> >(mid, pairs.end()));
	return mergePairsList(left, right);
}

void	PmergeMe::fordJohnsonList()
{
	/*
		If there is only 1 element, there is no need to sort
	*/
	if (lst.size() == 1)
		return ;

	/*
		Check if the number of elements is odd. If so, take the last number out
	*/
	int extra = 0;

	if (has_extra == true) 
	{
		extra = lst.back();
		lst.pop_back();
	}

	/*
		Now that we know there is an even number of elements, we split the numbers into pairs
		We also make sure that each pair is as follows: (smaller value, larger value)
	*/
	std::list<std::pair<int, int> > pairs;
	std::pair<int, int>	pair;
	list<int>::iterator it = lst.begin();
	int num_1;
	int num_2;

	while (it != lst.end())
	{
		num_1 = *it;
		++it;
		num_2 = *it;
		++it;
		if (num_1 < num_2)
			pair = std::pair<int, int>(num_1, num_2);
		else
			pair = std::pair<int, int>(num_2, num_1);
		pairs.push_back(pair);
	}

	/*
		Run the sorting algorithm
	*/
	pairs = mergeSortPairsList(pairs);

	/*
		Place all second (larger) elements into main and all first (smaller) elements into pend
	*/
	list<int> main;
	list<int> pend;

	for (list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back((*it).second);
		pend.push_back((*it).first);
	}

	/*
		Since the 1st element in pend will always be smaller than the 1st element in main, 
		We can immediately move it into main
	*/
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	/*
		Creates a list of integers that is sorted according to jacobsthal numbers
		E.g.	Jacobsthal numbers: 1 3 5 11
				Index of elements in pend to be inserted to tmp: [1] [3] 2 [5] 4 [11] 10 9 8 7 6
				* Note that in the actual index we need to -1
				So if we get a sequence of let's say [5, 2, 3, 1],
				We will get [5, 3, 2, 1]
	*/
	list<int> tmp;
	int n = 1;
	int jacob = jacobsthal(n);
	list<int>::iterator list_it;

	while (true){
		if (tmp.size() == pend.size())
			break;
		else if (jacob == jacobsthal(n - 1))
		{
			n++;
			jacob = jacobsthal(n);
		}
		else
		{
			if (jacob > (int)pend.size())
				jacob = (int)pend.size();
			list_it = pend.begin();
			std::advance(list_it, jacob - 1);
			tmp.push_back(*list_it);
			jacob--;
		}
	}

	/*
		std::lower_bound performs a binary search
		We will use this to insert our elements in tmp, as well as the extra value to the correct positions
	*/
	for (list<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
		main.insert(std::lower_bound(main.begin(), main.end(), *it), *it);
	if (has_extra == true)
		main.insert(std::lower_bound(main.begin(), main.end(), extra), extra);
	lst = main;

	return ;
}
