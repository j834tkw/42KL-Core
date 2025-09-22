#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

// The assignment operator is a = b; In the same way, you can take b as an argument, make it return a reference to a, and 
// configure the inside of the function so that the value of b is contained in a. In fact, if the developer does not create 
// it themselves, the compiler will create it itself, but since it may not work as the developer intended, the correct way is 
// to implement it directly.

// A copy constructor is a constructor that receives a reference to the same class as an argument and creates a new class 
// using the value of that reference. Deep copy -- Because it copies values, it is used to create an object that 
// is identical to the original object but is independent.

// If you look at the assignment output example, you can see that the getRawBits function is used to get the value when doing 
// copy or copy assignment. Therefore, it was implemented using the corresponding function.

// The const of the argument is used at the end of the function getRawBits to ensure that the value of this class is not 
// changed in this function, to ensure that the value of the argument is not changed.