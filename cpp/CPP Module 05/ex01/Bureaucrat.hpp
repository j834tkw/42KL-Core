#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const	std::string name;
		int					grade;

	public:
		std::string	const	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form);

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat(std::string inputName, int inputGrade);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what(void) const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what(void) const throw()
				{
					return ("Grade too low");
				}
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif