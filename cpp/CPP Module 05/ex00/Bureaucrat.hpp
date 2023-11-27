#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const	std::string name;
		int					grade;

	public:
		std::string	getName();
		int			getGrade();

		Bureaucrat &Bureaucrat::operator++(void);
		Bureaucrat	Bureaucrat::operator++(int);
		Bureaucrat &Bureaucrat::operator--(void);
		Bureaucrat	Bureaucrat::operator--(int);

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat(std::string const & type);
		Bureaucrat& operator=(const Bureaucrat& obj);
		virtual ~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
			const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char * what(void) const throw();
		};
};

#endif