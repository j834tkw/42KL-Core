#include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	cout << "Materia is used at" << target.getName() << endl;
}

/*==================================================================================================*/
/*								Canonical Orthodox stuff idk										*/
/*==================================================================================================*/

AMateria::AMateria()
{
	this->type = "idk";
}

AMateria::AMateria(const AMateria &AMateria)
{
	*this = AMateria;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria &AMateria::operator = (const AMateria &obj)
{
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

AMateria::~AMateria()
{
}
