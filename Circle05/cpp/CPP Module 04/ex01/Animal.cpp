#include "Animal.hpp"

using std::cout;
using std::endl;
using std::string;

string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	cout << "[Animal] *incomprehendible noises*" << endl;
}

Animal::Animal()
{
	cout << "[Animal] Default constructor called" << endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &animal)
{
	cout << "[Animal] Copy constructor called" << endl;
	*this = animal;
}

Animal &Animal::operator = (const Animal &animal)
{
	cout << "[Animal] Copy assignment operator called" << endl;
	if (this == &animal)
		return (*this);
	this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	cout << "[Animal] Destructor called" << endl;
}
