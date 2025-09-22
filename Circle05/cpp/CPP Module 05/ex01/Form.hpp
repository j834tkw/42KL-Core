#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class Form
{
	private:
		const string	name;
		const int		signGradeReq;
		const int		execGradeReq;
		bool			isSigned;

	public:
		string const	getName() const;
		bool			getIsSigned() const;
		int				getSignGradeReq() const;
		int				getExecGradeReq() const;
		void			beSigned(Bureaucrat &bureaucrat);

		Form();
		Form(const string name, const int signGradeReq, const int execGradeReq);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form();

		class GradeTooHighException: public exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException: public exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
};

ostream &operator << (ostream &outs, const Form &form);

#endif