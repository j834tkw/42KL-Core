#include "WrongAnimal.hpp"

using std::cout;
using std::endl;
using std::string;

string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	cout << "[WrongAnimal] *incomprehendible noises but grammarly incorrect*" << endl;
}

WrongAnimal::WrongAnimal()
{
	cout << "[WrongAnimal] Default constructor called" << endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	cout << "[WrongAnimal] Copy constructor called" << endl;
	*this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &WrongAnimal)
{
	if (this == &WrongAnimal)
		return (*this);
	this->type = WrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << "[WrongAnimal] Destructor called" << endl;
}
