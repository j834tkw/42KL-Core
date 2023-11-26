#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed	&Fixed::operator=(const Fixed &obj)
{
	cout << "Copy assignment operator called" << endl;
	this->value = obj.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const bits)
{
	this->value = bits;
}

std::ostream & operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int		Fixed::toInt( void ) const
{														// E(i)-1.2: 2560/256 = 10
	int		returnInt = (int)value / (int)(1 << bits); 	// E(f)-1.2: 10860/256 = 42.421875, typecasted to int so 42
	return (returnInt);
}

float	Fixed::toFloat( void ) const
{																// E(i)-1.3: 2560/256 = 10
	float	returnFloat = (float)value / (float)(1 << bits);	// E(f)-1.3: 10860/256 = 42.421875, typecasted to float so 42.4219, since float is max 7 digit including "."
	return (returnFloat);
}

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(int intNum) // =========================================|||EXAMPLES START HERE|||========================================== //
{
	cout << "Int constructor called" << endl; // Example (int) - 1st example, part 1
	this->value = (intNum << bits); // E(i)-1.1: The int 10 becomes 2560
}

Fixed::Fixed(float floatNum)
{
	cout << "Float constructor called" << endl;
	this->value = roundf(floatNum * (1 << bits)); // E(f)-1.1: the float 42.42 becomes 10859.52, rounded to 10860
}

Fixed::Fixed(const Fixed &obj)
{
	cout << "Copy constructor called" << endl;
	*this = obj;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}
