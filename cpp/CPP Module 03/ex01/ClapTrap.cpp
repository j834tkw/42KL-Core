#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ClapTrap::ClapTrap(void)
{
	this->name = "No name";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	cout << "[ClapTrap] Default constructor called" << endl;
}
	
ClapTrap::ClapTrap(string name)
{
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	cout << "[ClapTrap] Constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	cout << "[ClapTrap] Copy constructor called" << endl;
}

ClapTrap::~ClapTrap(void)
{
	cout << "[ClapTrap] Destructor called" << endl;
}

ClapTrap	&ClapTrap::operator =(const ClapTrap &obj)
{
	cout << "[ClapTrap] Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->hitPoints || !this->energyPoints)
		cout << "ClapTrap " << this->name << " cannot act" << endl;
	else
	{
		this->energyPoints--;
		cout << "ClapTrap " << this->name << " attacks " << target << ", dealing " << this->attackDamage << " damage, " << this->energyPoints << " energy remaining" << endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints || !this->energyPoints)
		cout << "ClapTrap " << this->name << " cannot act" << endl;
	else
	{
		if (amount > this->hitPoints)
			hitPoints = 0;
		else
			this->hitPoints -= amount;
		cout << "ClapTrap " << this->name << " has taken " << amount << " damage, " << this->hitPoints << " hp remaining" << endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints || !this->energyPoints)
		cout << "ClapTrap " << this->name << " cannot act" << endl;
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		cout << "ClapTrap " << this->name << " has recovered " << amount << " hp, " << this->hitPoints << " hp remaining, " << this->energyPoints << " energy remaining" << endl;
	}
}
