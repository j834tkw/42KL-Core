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
	cout << "getRawBits member function called" << endl;
	return (this->value);
}

void	Fixed::setRawBits(int const bits)
{
	this->value = bits;
}

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	cout << "Copy constructor called" << endl;
	this->value = obj.getRawBits();
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}
