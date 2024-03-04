#include "easyfind.hpp"

using std::endl;
using std::cout;
using std::cerr;

int main(void)
{
	std::vector<int>	veccie;
	std::list<int>		listie;

	for (int i = 0; i < 5; i++)
	{
		veccie.push_back(i);
		listie.push_back(i);
	}

	cout << *(easyfind(veccie, 2)) << endl;
	cout << *(easyfind(listie, 2)) << endl;
	try
	{
		cout << *(easyfind(veccie, 10)) << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
	}

	return (0);
}