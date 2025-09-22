#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

int main(int ac, char **av)
{
	btcExchange btc;

	if (ac != 2)
	{
		cout << "Please use only one file as parameter" << endl;
		return (0);
	}
	try
	{
		btc.retrieveData();
		btc.readInput(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Please make sure input file is formatted correctly" << endl;
	}
}
