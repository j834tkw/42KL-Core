#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

using std::cout;
using std::endl;

	// "presidential pardon",
	// "robotomy request",
	// "shrubbery creation"

int main(void)
{
	try
	{
		Intern RandomDude3;
		Bureaucrat B1("dark and black person", 1);
		AForm *F1 = RandomDude3.makeForm("presidential pardon", "racist");

		B1.signForm(*F1);
		B1.executeForm(*F1);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	cout << endl;

	// try
	// {
	// 	Intern RandomDude2;
	// 	Bureaucrat B2("le babi oink oink", 1);
	// 	AForm *F2 = RandomDude2.makeForm("robotomy request", "chicharron");

	// 	B2.signForm(*F2);
	// 	B2.executeForm(*F2);
	// }
	// catch (const std::exception& e)
	// {
	// 	cout << e.what() << endl;
	// }

	cout << endl;

	// try
	// {
	// 	Intern RandomDude3;
	// 	Bureaucrat B3("dunno", 1);
	// 	AForm *F3 = RandomDude3.makeForm("shrubbery creation", "idk");

	// 	B3.signForm(*F3);
	// 	B3.executeForm(*F3);
	// }
	// catch (const std::exception& e)
	// {
	// 	cout << e.what() << endl;
	// }

	return (0);
}
