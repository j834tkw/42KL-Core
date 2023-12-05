#include <Intern.hpp>

using std::cout;
using std::endl;
using std::string;

//--------------------------------------------------------------------Le stuff------------------------------------------------------------------//

Intern::Intern()
{
	cout << "[Intern] Default constructor called" << endl;
}

Intern::Intern(const Intern &obj)
{
	cout << "[Intern] Copy constructor called" << endl;
}

Intern &Intern::operator = (const Intern &obj)
{
	cout << "[Intern] Copy assignment operator called" << endl;
	(void) obj;
	return (*this);
}

Intern::~Intern()
{
	cout << "[Intern] Destructor called" << endl;
}
