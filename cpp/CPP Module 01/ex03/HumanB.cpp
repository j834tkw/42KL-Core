#include "HumanB.hpp"

using std::string;
using std::cout;
using std::endl;

void HumanB::attack(void)
{
	cout << name << " attacks using a " << weapon->getType() << endl;
}

void	HumanB::setWeapon(Weapon &weaponType)
{
	weapon = &weaponType;
}

HumanB::HumanB(string name)
{
	this->name = name;
	cout << this->name << " was constructed" << endl;
}

HumanB::~HumanB(void)
{
	cout << this->name << " was deconstructed" << endl;
}
