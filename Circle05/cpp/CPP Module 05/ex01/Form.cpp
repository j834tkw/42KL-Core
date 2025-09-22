#include "Form.hpp"

using std::cout;
using std::endl;
using std::string;

string const Form::getName() const
{
	return (name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getSignGradeReq() const
{
	return (signGradeReq);
}

int	Form::getExecGradeReq() const
{
	return (execGradeReq);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGradeReq)
		throw Form::GradeTooLowException();
	else
		isSigned = true;
}

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

Form::Form(): name("No name"), signGradeReq(1), execGradeReq(1), isSigned(false)
{
	cout << "[Form] Default constructor called" << endl;
}

Form::Form(const string name, const int signGradeReq, const int execGradeReq): name(name), signGradeReq(signGradeReq), execGradeReq(execGradeReq), isSigned(false)
{
	cout << "[Form] Constructor called" << endl;
	if (signGradeReq < 1 || execGradeReq < 1)
		throw (Form::GradeTooHighException());
	else if  (signGradeReq > 150 || execGradeReq > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &form): name(form.getName()), signGradeReq(form.getSignGradeReq()), execGradeReq(form.getExecGradeReq()), isSigned(form.getIsSigned())
{
	cout << "[Form] Copy constructor called" << endl;
}

Form &Form::operator = (const Form &form)
{
	cout << "[Form] Copy assignment operator called" << endl;
	if (this == &form)
		return (*this);
	*this = Form(form);
	return (*this);
}

Form::~Form()
{
	cout << "[Form] Destructor called" << endl;
}

//--------------------------------------------------------------------Le stuff 2----------------------------------------------------------------//

std::ostream &operator<<(std::ostream &out, Form &form)
{
	out << "Form : " << form.getName();
	if (form.getIsSigned())
		out << ", signature received";
	else if (!form.getIsSigned())
		out << ", signature not received";
	out << "; Minumum grade required to sign: " << form.getSignGradeReq() << "; Minimum grade required to execute: " << form.getExecGradeReq();
	return (out);
}