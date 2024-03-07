#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <deque>

class RPN
{
	private:
		std::deque<int>		numbers;
		std::deque<char>	operations;

	public:
		RPN();
		RPN(const RPN &obj);
		RPN	&operator = (const RPN &obj);
		~RPN();

		void	retrieveData(char *line);
};

#endif