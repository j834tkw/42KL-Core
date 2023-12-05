#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

std::string	const Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
{
	return(this->grade);
}

void    Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	cout << "Incremented" << endl;
}

void    Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	cout << "Decremented" << endl;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSigned() == true)
	{
		cout << "The form [" << form.getName() << "] is already signed" << endl;
		return ;
	}

	try
	{
		form.beSigned(*this);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		cout << "Bureaucrat " << this->getName() << " is unable to sign the form [" << form.getName() << "] due to not meeting the minumum grade requirements of the form" << endl;
	}
	if (form.getIsSigned() == true)
			cout << "Bureaucrat " << this->getName() << " has signed the form [" << form.getName() << "]" << endl;
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute((*this));
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " was not able to execute the form [" << form.getName() << "] because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " has successfully executed the form [" << form.getName() << "]" << std::endl;
}

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

Bureaucrat::Bureaucrat(void) : name("No name"), grade(100)
{
	cout << "[Bureaucrat] Default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
	cout << "[Bureaucrat] Copy constructor called" << endl;
}

Bureaucrat::Bureaucrat(std::string inputName, int inputGrade) : name(inputName), grade(inputGrade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		cout << "[Bureaucrat] Constructor called" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	this->grade = obj.grade;
	cout << "[Bureaucrat] Copy assignment operator called" << endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "[Bureaucrat] Destructor called" << endl;
}

//--------------------------------------------------------------------Le stuff 2----------------------------------------------------------------//

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << "Name: " << obj.getName() << ", grade: " << obj.getGrade();
	return (out);
}