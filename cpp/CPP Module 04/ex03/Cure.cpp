#include "Cure.hpp"

using std::cout;
using std::endl;
using std::string;

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	cout << "*heals " << target.getName() << "'s wounds*" << endl;
}

/*==================================================================================================*/
/*								Canonical Orthodox stuff idk										*/
/*==================================================================================================*/

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure &Cure) : AMateria()
{
	this->type = "cure";
	*this = Cure;
}

Cure &Cure::operator = (const Cure &obj)
{
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

Cure::~Cure()
{
}
