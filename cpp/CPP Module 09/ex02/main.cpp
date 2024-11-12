#include "PmergeMe.hpp"

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	PmergeMe pm;

	if (argc == 1)
	{
		cerr << "Error: No arguments provided" << endl;
		return (-1);
	}

	try
	{
		pm.initFromCharArr(argc, argv);
		pm.runFordJohnsons();
		pm.printResults();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

}