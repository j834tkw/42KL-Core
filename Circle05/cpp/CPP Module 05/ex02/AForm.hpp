#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class AForm
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
		void			execute(Bureaucrat const &executor) const;
		virtual void	action() const = 0;

		AForm();
		AForm(const string name, const int signGradeReq, const int execGradeReq);
		AForm(const AForm &form);
		AForm &operator = (const AForm &form);
		virtual ~AForm();

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
		class FormNotSignedException: public exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form not signed");
				}
		};
};

ostream &operator << (ostream &outs, const AForm &form);

#endif