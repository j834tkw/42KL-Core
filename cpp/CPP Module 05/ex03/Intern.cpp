#include "Intern.hpp"

using std::cout;
using std::endl;
using std::string;

AForm *Intern::createFormPP(std::string target) // "Function defined but not used" warning is only issued for functions with internal linkage ie static functions
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createFormRR(std::string target)	// a static function is a member function of a class associated with the class 
{												// itself rather than with an instance or object of the class
	return (new RobotomyRequestForm(target));	// Hence they can be called without creating an instance of the class
}

AForm *Intern::createFormSC(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(string newFormName, string newFormTarget)
{
	string	FromNameArray[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*(*functionArray[3])(string) = {&Intern::createFormPP, &Intern::createFormRR, &Intern::createFormSC};
	AForm	*form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (newFormName == FromNameArray[i])
		{
			form = (*functionArray[i])(newFormTarget); // each form has its own createForm function
			cout << "Intern creates " << newFormName << endl;
			return (form);
		}
	}
	if (!form) // if no form is created
		throw (Intern::InvalidFormException());

	return (form);
}

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

Intern::Intern()
{
	cout << "[Intern] Default constructor called" << endl;
}

Intern::Intern(const Intern &obj)
{
	cout << "[Intern] Copy constructor called" << endl;
	(void) obj;
}

Intern &Intern::operator = (const Intern &obj)
{
	cout << "[Intern] Copy assignment operator called" << endl;
	(void) obj;
	return (*this);
}

Intern::~Intern()
{
	cout << "[Intern] Destructor called" << endl;
}
