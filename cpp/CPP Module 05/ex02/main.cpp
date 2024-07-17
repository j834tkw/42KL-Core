#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

int main(void)
{
	try
	{
		Bureaucrat B1("Crewmate", 1);
		PresidentialPardonForm F1("Imposter");
		PresidentialPardonForm F2(F1);
		B1.signForm(F2);
		B1.executeForm(F2);
	}
	catch (const std::exception& e) //catch any exception declared
	{
		cout << e.what() << endl;
	}

	cout << endl;

	try
	{
		Bureaucrat B2("NPC_0001", 145);
		Bureaucrat B3("Asimov", 1);
		RobotomyRequestForm F3("Noan");
		B2.signForm(F3); //cant sign form
		B3.signForm(F3);
		B2.executeForm(F3); //cant execute form
		B3.executeForm(F3);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	cout << endl;

	try
	{
		Bureaucrat B4("Most epic botanist or sum", 1);
		ShrubberyCreationForm F4("Tree");
		B4.signForm(F4);
		B4.executeForm(F4);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return (0);
}
