#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;
using std::string;

string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::action() const
{
	srand(time(0));
	int fiftyfifty = rand() % 2;

	if (fiftyfifty == 1)
		cout << this->getTarget() << " got beep-beep-boop-booped, damn" << endl;
	else
		cout << this->getTarget() << " did not become a cool construct" << endl;
}

// AForm *RobotomyRequestForm::createFormRR(std::string target)
// {
// 	return (new RobotomyRequestForm(target));
// }

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("Construct/Nikke wannabe")
{
	cout << "[RobotomyRequestForm] Default constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const newTarget) : AForm("Robotomy Request", 72, 45), target(newTarget)
{
	cout << "[RobotomyRequestForm] Constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("Robotomy Request", 72, 45), target(obj.target)
{
	cout << "[RobotomyRequestForm] Copy constructor called" << endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &obj)
{
	cout << "[RobotomyRequestForm] Copy assignment operator called" << endl;
	this->target = obj.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "[RobotomyRequestForm] Destructor called" << endl;
}