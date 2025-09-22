#include "Ice.hpp"

using std::cout;
using std::endl;
using std::string;

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	cout << "*shoots an ice bolt at " << target.getName() << "*" << endl;
}

/*==================================================================================================*/
/*								Canonical Orthodox stuff idk										*/
/*==================================================================================================*/

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &Ice) : AMateria()
{
	this->type = "ice";
	*this = Ice;
}

Ice &Ice::operator = (const Ice &obj)
{
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

Ice::~Ice()
{
}
