#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::atoi;

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

std::string btcExchange::retrieveInput(std::string line, std::string type)
{
	if (type == "date")
		return (line.substr(0, 10));
	else if (type == "value")
	{
		if (line.rfind('|') == line.npos)
			return ("");
		return (line.substr(line.rfind('|') + 2));
	}
	return ("");
}

bool btcExchange::isValidDate(std::string date)
{
	int	year;
	int month;
	int	day;

	try
	{
		year = atoi(date.substr(0, 4).c_str());
		month = atoi(date.substr(5, 2).c_str());
		day = atoi(date.substr(8, 2).c_str());
	}
	catch(const std::invalid_argument& e)
	{
		cerr << "Error: Bad input => " << date << endl;
		return (0);
	}
	
	(void)year;
	if ((month < 1 || month > 12) || (day < 1 || day > 31))
	{
		cerr << "Error: Bad input => " << date << endl;
		return (0);
	}
	return (1);
}

bool btcExchange::isValidValue(std::string value)
{
	int valueC;

	if (value == "")
	{
		cerr << "Error: No value given" << endl;
		return (0);
	}

	try
	{
		valueC = atof(value.c_str());
	}
	catch(const std::out_of_range& e)
	{
		cerr << "Error: too large a number." << endl;
		return (0);
	}
	
	if (valueC < 0)
	{
		cerr << "Error: not a positive number." << endl;
		return (0);
	}
	return (1);
}

void btcExchange::retrieveData()
{
	std::fstream	file;
	string			line;
	string			date;
	float			rate;

	file.open("data.csv", std::fstream::in);
	if (!file.is_open())
	{
		cerr << "Unable to open file" << endl;
		return ;
	}
	while (std::getline(file, line))
	{
		date = line.substr(0, 10);
		rate = atof(line.substr(line.rfind(',')).c_str());

		if (!isValidDate(date))
			cerr << "Error in data.csv file found!" << endl;
		else
			data.insert(std::make_pair(date, rate));
	}
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
		date = retrieveInput(line, "date");
		value = retrieveInput(line, "value");

		if (isValidDate(date) && isValidValue(value))
			cout << date << ": " << value << endl;
	}
}