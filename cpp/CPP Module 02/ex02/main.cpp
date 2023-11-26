#include "Fixed.hpp"

int main( void ) {
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

// int main(void)
// {
// 	Fixed a;
// 	Fixed b;

// 	a = 10;
// 	b = 5;

// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "is a larger than b? " << (a > b) << std::endl;
// 	std::cout << "is a smaller than b? " << (a < b) << std::endl;
// 	std::cout << "is a larger or equal than b? " << (a >= b) << std::endl;
// 	std::cout << "is a smaller or equal than b? " << (a <= b) << std::endl;
// 	std::cout << "is a equal than b? " << (a == b) << std::endl;
// 	std::cout << "is a not equal than b? " << (a != b) << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "a + b = " << (a + b) << std::endl;
// 	std::cout << "a - b = " << (a - b) << std::endl;
// 	std::cout << "a * b = " << (a * b) << std::endl;
// 	std::cout << "a / b = " << (a / b) << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "prefix increment a: " << ++a << std::endl;
// 	std::cout << "it is now: " << a << std::endl;
// 	std::cout << "postfix increment a: " << a++ << std::endl;
// 	std::cout << "it is now: " << a << std::endl;
// 	std::cout << "prefix decrement a: " << --a << std::endl;
// 	std::cout << "it is now: " << a << std::endl;
// 	std::cout << "postfix decrement a: " << a-- << std::endl;
// 	std::cout << "it is now: " << a << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "the max between a and b is: " << Fixed::max(a, b) << std::endl;
// 	std::cout << "the min between a and b is: " << Fixed::min(a, b) << std::endl;
// }

// Prefix & postfix operators cant be differenciated by return type, only by parameter list

// The compiler uses the int argument to distinguish between the prefix and postfix operators.
