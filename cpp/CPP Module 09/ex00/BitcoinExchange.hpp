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
#include <algorithm>

class btcExchange
{
	private:
		std::map <std::string, float> data; // a map contains key-value pairs with unique keys

	public:
		btcExchange();
		~btcExchange();
		btcExchange& operator=(btcExchange const &var);
		btcExchange(btcExchange const &var);

		std::string trimStr(std::string str);
		std::string retrieveInput(std::string line, std::string type);
		void readInput(char *inputPath);
		void retrieveData();
		float calcValue(std::string date, float value);
	
		bool isValidDate(std::string date, int useCase);
		bool isValidValue(std::string value, int useCase);
};

#endif