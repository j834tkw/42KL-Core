#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>

class Intern
{
	public:
		Intern();
		Intern(const Intern &intern);
		Intern &operator = (const Intern &intern);
		~Intern();

		AForm* makeForm(string formBureau, string formTarget);

		class FormNotExistException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form does not exist");
				}
		};
};

#endif