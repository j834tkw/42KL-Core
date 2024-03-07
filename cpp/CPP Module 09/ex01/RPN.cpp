#include "RPN.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cerr;

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

void	RPN::retrieveData(char *line)
{

}