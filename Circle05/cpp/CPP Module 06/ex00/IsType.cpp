#include "ScalarConverter.hpp"

using std::cout;
using std::endl;
using std::string;
using std::isalpha;
using std::isprint;
using std::isdigit;
using std::isnan;

int		determineType(string input)
{
	if (isChar(input))
		return (1);
	else if (isInt(input) || isFloat(input) || isDouble(input))
		return (2);
	else if (isLiteral(input))
		return (3);
	else
		return (0);
}

bool    isChar(string input)
{
	if (input.length() == 1) // check if only 1 char
		if (isalpha(input[0])) // check if is alphabet
			return true;

	return false;
}

bool    isInt(string input)
{
	int i = 0;
	int k = 0;

	if (input[0] == '-' || input[0] == '+') // skip signs
		i++;

	for (int j(i); input[j]; j++)
	{
        if (!isdigit(input[j])) // return false upon encountering non digit
            return false;
		k++;
	}

	if (k == 0) // check if no digit after + or -
		return false;

	return true;
}

bool    isFloat(string input)
{
	int		i = 0;
	int		len = input.length();
	int		foundDot = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;

	if (input[len - 1] != 'f' || input[len - 2] == '.' || input[i] == '.') // if it doesn't end with 'f' / its .digitf / ends with dot
		return false;

	for (int j(i); input[j] != 'f'; j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return false;
		if (input[j] == '.')
			foundDot++;
	}

	if (foundDot != 1) // if not 1 decimal point
		return false;

	return true;
}

bool    isDouble(string input)
{
	int		i = 0;
	int		len = input.length();
	int		foundDot = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;

	if (input[len - 1] == '.' || input[i] == '.') // if its .digit / ends with dot
		return false;

	for (int j(i); input[j]; j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return false;
		if (input[j] == '.')
			foundDot++;
	}

	if (foundDot != 1)
		return false;

	return true;
}

bool    isLiteral(string input)
{
	if ((input.compare("nan") == 0) || (input.compare("nanf") == 0)
	|| (input.compare("+inf") == 0) || (input.compare("-inf") == 0)
	|| (input.compare("+inff") == 0) || (input.compare("-inff") == 0)) // check if its any of these
	{
		return true;
    }

    return false;
}
