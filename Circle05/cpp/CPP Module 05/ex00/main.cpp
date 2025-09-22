#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("bozo", 125);
		Bureaucrat b("ozob", 5);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		a.incrementGrade();
		b.decrementGrade();
	
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat a("man", 150);

		std::cout << a << std::endl;
		a.decrementGrade();	
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat b("Man", 1);

		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

return (0);
}

// Exception handling in C++ consist of three keywords: try, throw and catch:
// 	-	The try statement allows you to define a block of code to be tested for errors while it is being executed.
// 	-	The throw keyword throws an exception when a problem is detected, which lets us create a custom error.
// 	-	The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.