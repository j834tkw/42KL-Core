#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::string;

string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::action() const
{
	cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << endl;
}

// AForm *PresidentialPardonForm::createFormPP(std::string target)
// {
// 	return (new PresidentialPardonForm(target));
// }

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("Late president's assassinator")
{
	cout << "[PresidentialPardonForm] Default constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const newTarget) : AForm("Presidential Pardon", 25, 5), target(newTarget)
{
	cout << "[PresidentialPardonForm] Constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("Presidential Pardon", 25, 5), target(obj.target)
{
	cout << "[PresidentialPardonForm] Copy constructor called" << endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &obj)
{
	cout << "[PresidentialPardonForm] Copy assignment operator called" << endl;
	this->target = obj.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "[PresidentialPardonForm] Destructor called" << endl;
}
