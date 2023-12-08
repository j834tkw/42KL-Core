#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cmath>
#include <iomanip>

using std::string;
using std::endl;
using std::cout;

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		static void		convert(string input);

		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator = (const ScalarConverter &obj);
		~ScalarConverter();
};

int		determineType(string input);	// gei lou wanker get fking abandoned
										// can't access a non static class member from a static method
										// ok nvm din read subject properly class only contains 1 static func

// IsType functions --------------------------------------------------------------------
bool    isChar(string input);
bool    isInt(string input);
bool    isFloat(string input);
bool    isDouble(string input);
bool    isLiteral(string input);

// Print functions ---------------------------------------------------------------------
void	convChar(string input);
void	convNum(string input);
void	convLiteral(string input);

#endif