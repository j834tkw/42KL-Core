#include "HumanA.hpp"

using std::string;
using std::cout;
using std::endl;

void HumanA::attack(void)
{
	cout << name << " attacks using a " << weapon.getType() << endl;
}

HumanA::HumanA(string name, Weapon &weaponType) : weapon(weaponType)
{
	this->name = name;
	cout << this->name << " was constructed" << endl;
}

HumanA::~HumanA(void)
{
	cout << this->name << " was deconstructed" << endl;
}
