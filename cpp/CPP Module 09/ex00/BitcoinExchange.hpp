#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

class btcExchange
{
	private:
		std::map <std::string, float> data; // a map contains key-value pairs with unique keys

	public:
		btcExchange();
		~btcExchange();
		btcExchange& operator=(btcExchange const &var);
		btcExchange(btcExchange const &var);

		void addData(std::string date, float value);
		void readInput(char *inputPath);

		std::map<std::string, float> getData();
		std::vector<std::string> splitString(std::string str, char delimiter);
};

#endif