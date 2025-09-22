#include "ScalarConverter.hpp"

using std::cout;
using std::endl;
using std::string;
using std::isnan;
using std::fixed;
using std::setprecision;
using std::numeric_limits;

void	convChar(string input)
{
	char thing = input[0];

	cout << "Char: " << thing << endl;
	cout << "Int: " << static_cast<int>(thing) << endl; // static_cast is a compile-time cast. It does things like implicit conversions between types
	cout << "Float: " << fixed << setprecision(1) << static_cast<float>(thing) << "f" << endl;
	cout << "Double: " << fixed << setprecision(1) << static_cast<double>(thing) << endl;
}

void	convNum(string input)
{
	double	thing = strtod(input.c_str(), NULL); // double can store the largest number among the 4 types, so its used to compare with intmin & intmax

	if (thing < 255 && thing > -1) // if u isprint a value too large it can segfault wtf is this crap
	{
		if (isprint(thing) != 0 && thing == floor(thing)) // check if its a double/float
			cout << "Char: " << static_cast<char>(thing) << endl;
		else
			cout << "Char: Its unprintable, unfortunately, or you didnt use whole numbers" << endl;
	}
	else
		cout << "Char: Man ur number is beyond what ascii has bro what u want" << endl;

	if ((thing > numeric_limits<int>::max() || thing < numeric_limits<int>::min())) // check if bigger/smaller than int max/min
		cout << "Int: Num is beyond int mate chill" << endl;
	else
		cout << "Int: " << static_cast<int>(thing) << endl;

	cout << "Float: " << fixed << setprecision(1) << static_cast<float>(thing) << "f" << endl; // if number is sufficiently extreme. itll print inff or -inff

	cout << "Double: " << fixed << setprecision(1) << static_cast<double>(thing) << endl;
}

void	convLiteral(string input)
{
	cout << "Char: Impossibruh" << endl;
	cout << "Int: Aint no way" << endl;

	if (input == "+inff" || input == "-inff" || input == "nanf") // if its for float
		cout << "Float: " << input << endl;
	else
		cout << "Float: " << input << "f" << endl; // add f

	if (input == "+inff" || input == "-inff" || input == "nanf")
		cout << "Double: " << input.erase(input.length() - 1) << endl; // remove last f
	else
		cout << "Double: " << input << endl;
}