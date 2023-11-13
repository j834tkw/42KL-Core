#include "Weapon.hpp"

using std::string;
using std::cout;
using std::endl;

const string Weapon::getType(void)
{
	const string &typeRef = type;
	return (typeRef);
}

void Weapon::setType(string newtype)
{
	type = newtype;
}

Weapon::Weapon(string type)
{
	this->type = type;
	cout << this->type << " was constructed" << endl;
}

Weapon::~Weapon(void)
{
	cout << this->type << " was deconstructed" << endl;
}
