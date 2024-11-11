#include "PmergeMe.hpp"

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	struct timeval	start;
	struct timeval	end;
	std::string	str;
	PmergeMe pm;

	if (argc == 1)
	{
		cerr << "Error: No arguments provided" << endl;
		return (-1);
	}

	try
	{
		pm.initFromCharArr(argc, argv);

		gettimeofday(&start, NULL);
		pm.fordJohnsonVector();
		pm.fordJohnsonList();
		gettimeofday(&end, NULL);


		for (long unsigned int i = 0; i < pm.getOg().size(); i++)
			cout << pm.getOg()[i] << " ";
		cout << endl;
		for (long unsigned int i = 0; i < pm.getVec().size(); i++)
			cout << pm.getVec()[i] << " ";
		cout << endl;
		std::list<int> e = pm.getLst();
		for (std::list<int>::iterator it = e.begin(); it != e.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

}