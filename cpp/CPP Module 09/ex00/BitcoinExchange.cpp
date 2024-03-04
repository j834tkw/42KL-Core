#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cerr;

btcExchange::btcExchange()
{
}

btcExchange::~btcExchange()
{
}

btcExchange &btcExchange::operator=(btcExchange const &var)
{
	this->data = var.data;
	return (*this);
}

btcExchange::btcExchange(btcExchange const &var)
{
	*this = var;
}

void btcExchange::addData(std::string date, float value)
{
	this->data.insert(std::make_pair(date, value));
}

void btcExchange::readInput(char *inputPath)
{
	std::fstream	input;
	string			line;
	string			date;
	string			value;

	input.open(inputPath, std::fstream::in);
	if (!input.is_open())
	{
		cerr << "Unable to open file" << endl;
		return ;
	}

	while (std::getline(input, line))
	{
		date = line.substr(0, line.find('|') - 1); 
		value = line.substr(line.rfind('|') + 2);
		cout << date << ": " << value << endl;
		// check valid input next
	}
}