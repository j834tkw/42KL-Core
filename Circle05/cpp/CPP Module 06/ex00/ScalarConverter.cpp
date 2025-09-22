#include "ScalarConverter.hpp"

using std::cout;
using std::endl;
using std::string;
using std::isalpha;
using std::isprint;
using std::isdigit;
using std::isnan;

void	ScalarConverter::convert(string input)
{
	switch (determineType(input))
	{
		case 1:
			convChar(input);
			break;
		case 2:
			convNum(input.c_str());
			break;
		case 3:
			convLiteral(input.c_str());
			break;

		default:
			cout << "Invalid type, input only one from char, int, float or double" << endl;
	}
	return ;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

ScalarConverter::ScalarConverter()
{
	cout << "[ScalarConverter] Default constructor called" << endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	cout << "[ScalarConverter] Copy constructor called" << endl;
	*this = obj;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &obj)
{
	cout << "[ScalarConverter] Copy assignment operator called" << endl;
	if (this == &obj)
		return (*this);
	(void) obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	cout << "[ScalarConverter] Destructor called" << endl;
}
