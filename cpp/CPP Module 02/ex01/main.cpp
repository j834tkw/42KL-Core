#include "Fixed.hpp"

int main( void ) {
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.432f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

// << function overloading
// It is declared separately rather than as a member function because the left operands are streams from the standard library, 
// and you cannot add member functions to those.
// Example: 
// If you define your operator overloaded function as member function, then the compiler translates expressions like s1 + s2 
// into s1.operator+(s2). That means, the operator overloaded member function gets invoked on the first operand.

