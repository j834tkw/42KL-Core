#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("test", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat a("a", 125);
		Bureaucrat b("b", 5);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.incrementGrade();
		b.decrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.incrementGrade();
		b.decrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
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