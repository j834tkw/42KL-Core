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

btcExchange &btcExchange::operator=(btcExchange const &obj)
{
	this->data = obj.data;
	return (*this);
}

btcExchange::btcExchange(btcExchange const &obj)
{
	*this = obj;
}

std::string btcExchange::trimStr(std::string str)
{
	str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
	return (str);
}

std::string btcExchange::retrieveInput(std::string line, std::string type)
{
	if (type == "date")
		return (line.substr(0, 10));
	else if (type == "value")
	{
		if (line.rfind('|') == line.npos)
			return ("");
		return (line.substr(line.rfind('|') + 1));
	}
	return ("");
}

bool btcExchange::isValidDate(std::string date, int useCase)
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
		if (useCase)
			cerr << "Error: Bad input => " << date << endl;
		return (0);
	}
	
	(void)year;
	if ((month < 1 || month > 12) || (day < 1 || day > 31))
	{
		if (useCase)
			cerr << "Error: Bad input => " << date << endl;
		return (0);
	}
	return (1);
}

bool btcExchange::isValidValue(std::string value, int useCase)
{
	int valueC;

	if (value == "")
	{
		if (useCase)
			cerr << "Error: No value given" << endl;
		return (0);
	}
	try
	{
		valueC = atof(value.c_str());
	}
	catch(const std::out_of_range& e)
	{
		if (useCase)
			cerr << "Error: too large a number." << endl;
		return (0);
	}
	
	if (valueC < 0)
	{
		if (useCase)
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
	string			rate;
	int				lineNum;

	file.open("data.csv", std::fstream::in);
	if (!file.is_open())
	{
		cerr << "Unable to open file" << endl;
		return ;
	}
	lineNum = 2;
	std::getline(file, line); // skip 1st line that is "date, exchange"
	while (std::getline(file, line))
	{
		date = line.substr(0, 10);
		rate = line.substr(line.rfind(',') + 1); // substr after ','

		if (!isValidDate(date, 0) || !isValidValue(rate, 0))
			cerr << "Error in data.csv found in line " << lineNum << "! Data omitted." << endl;
		else
			data.insert(std::make_pair(date, atof(rate.c_str())));
		lineNum++;
	}
}

float btcExchange::calcValue(std::string date, float value)
{
	std::map<std::string, float>::iterator pos;
	float	rate;

	// https://stackoverflow.com/questions/46375119/c-map-find-the-first-element-that-is-less-than-key
	// i.e. in keys of ints, search for 3.3, gives 4, decrement to 3, so its effectively always rounding down
	// why does lower_bound return <= key what the fukc
	pos = data.upper_bound(date);
	pos--; 
	if (pos == data.end())
	{
		cerr << "Date out of bounds!" << endl;
		return (-1);
	}
	else
		rate = pos->second; // -> second gives the value of the key
	return (rate * value);
}

void btcExchange::readInput(char *inputPath)
{
	std::fstream	input;
	string			line;
	string			date;
	string			value;
	float			calculated;

	input.open(inputPath, std::fstream::in);
	if (!input.is_open())
	{
		cerr << "Unable to open file" << endl;
		return ;
	}

	while (std::getline(input, line))
	{
		line = trimStr(line);
		date = retrieveInput(line, "date");
		value = retrieveInput(line, "value");

		if (isValidDate(date, 1) && isValidValue(value, 1))
		{
			calculated = calcValue(date, atof(value.c_str()));
			if (calculated >= 0)
				cout << date << " => " << value << " = " << calculated << endl;
		}
	}
}
