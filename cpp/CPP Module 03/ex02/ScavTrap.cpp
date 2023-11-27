#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap(void)
{
	this->name = "No name";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	cout << "[ScavTrap] Default constructor called" << endl;
}
	
ScavTrap::ScavTrap(string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	cout << "[ScavTrap] Constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap()
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	cout << "[ScavTrap] Copy constructor called" << endl;
}

ScavTrap::~ScavTrap(void)
{
	cout << "[ScavTrap] Destructor called" << endl;
}

ScavTrap	&ScavTrap::operator =(const ScavTrap &obj)
{
	cout << "[ScavTrap] Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->hitPoints || !this->energyPoints)
		cout << "ScavTrap " << this->name << " doen't wanna act" << endl;
	else
	{
		this->energyPoints--;
		cout << "ScavTrap " << this->name << " brutally assaults " << target << ", dealing " << this->attackDamage << " emotional damage, " << this->energyPoints << " energy remaining" << endl;
	}
}


void	ScavTrap::guardGate()
{
	cout << "ScavTrap " << name << " has ascended, becoming the keeper of gates, denier of entries" << endl;
}
