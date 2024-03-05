#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdlib.h>
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

		std::string retrieveInput(std::string line, std::string type);
		void readInput(char *inputPath);
		void retrieveData();
	
		bool isValidDate(std::string date);
		bool isValidValue(std::string value);
};

#endif