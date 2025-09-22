#include "FragTrap.hpp"

using std::cout;
using std::endl;
using std::string;

FragTrap::FragTrap(void)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	cout << "[FragTrap] Default constructor called" << endl;
}
	
FragTrap::FragTrap(string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	cout << "[FragTrap] Constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap()
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	cout << "[FragTrap] Copy constructor called" << endl;
}

FragTrap::~FragTrap(void)
{
	cout << "[FragTrap] Destructor called" << endl;
}

FragTrap	&FragTrap::operator =(const FragTrap &obj)
{
	cout << "[FragTrap] Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	cout << "FragTrap " << name << " raises a high-five and proceeds to high-five faces all over the place" << endl;
}
