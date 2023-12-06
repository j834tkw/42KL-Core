#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::string;

string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str()); // create file of target name + _shrubbery

		for (int i = 0; i < 4; i++) // insert 4 trees
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			std::endl;
		}
		outfile.close();
}

// AForm *ShrubberyCreationForm::createFormSC(std::string target)
// {
// 	return (new ShrubberyCreationForm(target));
// }

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), target("Botanist")
{
	cout << "[ShrubberyCreationForm] Default constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const newTarget) : AForm("Shrubbery Creation", 145, 137), target(newTarget)
{
	cout << "[ShrubberyCreationForm] Constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Shrubbery Creation", 145, 137), target(obj.target)
{
	cout << "[ShrubberyCreationForm] Copy constructor called" << endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &obj)
{
	cout << "[ShrubberyCreationForm] Copy assignment operator called" << endl;
	this->target = obj.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "[ShrubberyCreationForm] Destructor called" << endl;
}
