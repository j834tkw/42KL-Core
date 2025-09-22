#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

Bureaucrat::Bureaucrat(void) : name("No name"), grade(100)
{
	cout << "Default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
	cout << "Copy constructor called" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	this->grade = obj.grade;
	cout << "Copy assignment operator called" << endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Destructor called" << endl;
}

Bureaucrat::Bureaucrat(std::string inputName, int inputGrade) : name(inputName), grade(inputGrade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		cout << "Constructor called" << endl;
}

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
	if (this->grade - 1 < 1) // highest grade is 1, increment causes grade to - 1
		throw Bureaucrat::GradeTooHighException(); // whenever the custom exception occurs, the error message is displayed
	this->grade--;
	cout << "Incremented" << endl;
}

void    Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150) // lowest grade is 150, decrement causes grade to + 1
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	cout << "Decremented" << endl;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << "Name: " << obj.getName() << ", grade: " << obj.getGrade();
	return (out);
}