#include "AForm.hpp"

using std::cout;
using std::endl;
using std::string;

string const AForm::getName() const
{
	return (name);
}

bool	AForm::getIsSigned() const
{
	return (isSigned);
}

int	AForm::getSignGradeReq() const
{
	return (signGradeReq);
}

int	AForm::getExecGradeReq() const
{
	return (execGradeReq);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGradeReq)
		throw AForm::GradeTooLowException();
	else
		isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (isSigned == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getSignGradeReq())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " executed " << name << std::endl;
		this->action();
	}

}

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

AForm::AForm(): name("No name"), signGradeReq(1), execGradeReq(1), isSigned(false)
{
	cout << "[AForm] Default constructor called" << endl;
}

AForm::AForm(const string name, const int signGradeReq, const int execGradeReq): name(name), signGradeReq(signGradeReq), execGradeReq(execGradeReq), isSigned(false)
{
	cout << "[AForm] Constructor called" << endl;
	if (signGradeReq < 1 || execGradeReq < 1)
		throw (AForm::GradeTooHighException());
	else if  (signGradeReq > 150 || execGradeReq > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &Aform): name(Aform.getName()), signGradeReq(Aform.getSignGradeReq()), execGradeReq(Aform.getExecGradeReq()), isSigned(Aform.getIsSigned())
{
	cout << "[AForm] Copy constructor called" << endl;
}

AForm &AForm::operator = (const AForm &Aform)
{
	cout << "[AForm] Copy assignment operator called" << endl;
	if (this == &Aform)
		return (*this);
	this->isSigned = Aform.isSigned;
	return (*this);
}

AForm::~AForm()
{
	cout << "[AForm] Destructor called" << endl;
}

//--------------------------------------------------------------------Le stuff 2----------------------------------------------------------------//

std::ostream &operator<<(std::ostream &out, AForm &Aform)
{
	out << "Form : " << Aform.getName();
	if (Aform.getIsSigned())
		out << ", signature received";
	else if (!Aform.getIsSigned())
		out << ", signature not received";
	out << "; Minumum grade required to sign: " << Aform.getSignGradeReq() << "; Minimum grade required to execute: " << Aform.getExecGradeReq();
	return (out);
}
