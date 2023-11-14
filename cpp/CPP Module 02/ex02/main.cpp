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

// Fixed.hpp prefix & postfix operators

// To distinguish between prefix and postfix operators, the arguments are divided into void and int. There is 
// no special reason, but it serves to tell the compiler whether it is a prefix or a postfix by distinguishing it 
// with a dummy. This is a rule that arose because the compiler cannot distinguish whether the function is prefix 
// or postfix based on the return value of the argument.

// If you look at the prefix operator first, it returns a reference to *this after increasing or decreasing this→value. 
// If you see this for the first time if you are not familiar with the reference, it will be very confusing, but let's 
// think of it as C and look at it again. When getting the variable of this structure, use '.' Because '→' is used 
// instead of , you can tell that this is a pointer. Therefore, to return the original value of the pointer, use * as a 
// unary operator to return the value, and its referencing is done automatically. If you try to return just this instead 
// of *this, a compilation error will occur because you are trying to create a reference to a temporary object.
