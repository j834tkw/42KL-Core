#include "Fixed.hpp"

using std::cout;
using std::endl;

//==================================================================//
//																	//
//								CONSTRUCTORS						//
//																	//
//==================================================================//

Fixed::Fixed()
{
//	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(int intNum)
{
//	cout << "Int constructor called" << endl;
	this->value = (intNum << bits);
}

Fixed::Fixed(float floatNum)
{
//	cout << "Float constructor called" << endl;
	this->value = roundf(floatNum * (1 << bits));
}

Fixed::Fixed(const Fixed &obj)
{
//	cout << "Copy constructor called" << endl;
	*this = obj;
}

Fixed::~Fixed()
{
//	cout << "Destructor called" << endl;
}

//==================================================================//
//																	//
//								EX00								//
//																	//
//==================================================================//

Fixed	&Fixed::operator=(const Fixed &obj)
{
//	cout << "Copy assignment operator called" << endl;
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

//==================================================================//
//																	//
//								EX01								//
//																	//
//==================================================================//

std::ostream & operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int		Fixed::toInt( void ) const
{
	int		returnInt = (int)value / (int)(1 << bits);
	return (returnInt);
}

float	Fixed::toFloat( void ) const
{
	float	returnFloat = (float)value / (float)(1 << bits);
	return (returnFloat);
}

//==================================================================//
//																	//
//								EX02								//
//																	//
//==================================================================//

bool	Fixed::operator >(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator <(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator >=(Fixed const &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator <=(Fixed const &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator ==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator !=(Fixed const &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

Fixed	Fixed::operator +(Fixed const &ref) const
{
	Fixed ret(this->toFloat() + ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator -(Fixed const &ref) const
{
	Fixed ret(this->toFloat() - ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator *(Fixed const &ref) const
{
	Fixed ret(this->toFloat() * ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator /(Fixed const &ref) const
{
	Fixed ret(this->toFloat() / ref.toFloat());
	return (ret);
}

Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);

	this->value++;
	return (ret);
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);

	this->value--;
	return (ret);
}

Fixed &Fixed::min(Fixed &F1, Fixed &F2)
{
	if (F1 < F2)
		return (F1);
	return (F2);
}

Fixed const &Fixed::min(Fixed const &F1, Fixed const &F2)
{
	if (F1 < F2)
		return (F1);
	return (F2);
}

Fixed &Fixed::max(Fixed &F1, Fixed &F2)
{
	if (F1 > F2)
		return (F1);
	return (F2);
}

Fixed const &Fixed::max(Fixed const &F1, Fixed const &F2)
{
	if (F1 > F2)
		return (F1);
	return (F2);
}
