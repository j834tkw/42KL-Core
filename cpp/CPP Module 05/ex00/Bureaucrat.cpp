#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

Bureaucrat &Bureaucrat::operator++(void)
{
	this->grade++;
	return (*this); 
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	ret(*this);

	this->grade++;
	return (ret);
}

Bureaucrat &Bureaucrat::operator--(void)
{
	this->grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	ret(*this);

	this->grade--;
	return (ret);
}