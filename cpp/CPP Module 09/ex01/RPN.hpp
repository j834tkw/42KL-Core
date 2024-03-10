#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stack>
#include <exception>

class RPN
{
	private:
		std::stack<int>		numbers;

	public:
		RPN();
		RPN(const RPN &obj);
		RPN	&operator = (const RPN &obj);
		~RPN();

		void	runRPN(char *line);
		int		calculateRPN(char *line);
		int		executeOp(char op, int a, int b);
};

#endif