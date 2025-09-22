#include "RPN.hpp"

using std::cout;
using std::endl;

RPN::RPN()
{
}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN	&RPN::operator = (const RPN &obj)
{
	if (this == &obj)
		return (*this);
	this->numbers = obj.numbers;
	return (*this);
}

RPN::~RPN()
{
}

int		RPN::executeOp(char op, int a, int b)
{
	int	ret = 0;

	// b "operates" a bcuz b appears first in the expression
	// e.g. for "b a -", be will be put in stack first then a
	// 		the above expression equals to "b - a"
	switch(op)
	{
		case ('+'):
			ret = b + a;
			break;
		case ('-'):
			ret = b - a;
			break;
		case ('*'):
			ret = b * a;
			break;
		case ('/'):
			if (a == 0)
				throw std::runtime_error("Math error: Attempt to divide by zero detected");
			ret = b / a;
			break;
	}
	return (ret);
}

int	RPN::calculateRPN(char *line)
{
	int	i = -1;
	int	a = 0;
	int b = 0;

	while (line[++i])
	{
		if (line[i] == ' ')
			continue;
		if (isdigit(line[i]))
			numbers.push((int)(line[i] - '0'));
		else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
		{
			if (numbers.size() < 2)
				throw std::logic_error("Error: Insufficient numbers in expression");
			a = numbers.top();
			numbers.pop();
			b = numbers.top();
			numbers.pop();
			numbers.push(executeOp(line[i], a, b));
		}
		else
			throw std::logic_error("Error: Invalid input detected");
	}
	if (numbers.size() > 1)
		cout << "Error: There are extra unused number(s), displaying number at top of stack instead" << endl;
	return (numbers.top());
}

void RPN::runRPN(char *line)
{
	try
	{
		cout << calculateRPN(line) << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}