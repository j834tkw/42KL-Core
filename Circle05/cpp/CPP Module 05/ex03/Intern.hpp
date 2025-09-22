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
		AForm* makeForm(string newFormName, string newFormTarget);
		static AForm *createFormPP(std::string target);
		static AForm *createFormRR(std::string target);
		static AForm *createFormSC(std::string target);

		Intern();
		Intern(const Intern &intern);
		Intern &operator = (const Intern &intern);
		~Intern();
	
		class InvalidFormException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form does not exist");
				}
		};
};

#endif