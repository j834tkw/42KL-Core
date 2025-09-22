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
		std::string	const getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat(std::string inputName, int inputGrade);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();

		class GradeTooHighException : public std::exception // inherits all properties from the std::exception class
		{
			public: // The what() function returns a null terminated char* that may be used to identify the exception.
				const char * what(void) const throw() // The what() function from std::exception is overridden, which returns a custom error message string.
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