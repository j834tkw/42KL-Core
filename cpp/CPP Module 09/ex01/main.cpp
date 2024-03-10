#include "RPN.hpp"

using std::cout;
using std::endl;

int main(int ac, char **av)
{
	RPN			rpn;
	std::string	input;

	if (ac < 2 || !av[1])
	{
		cout << "Please input the expression as one string" << endl;
		return (-1);
	}
	rpn.runRPN(av[1]);
}