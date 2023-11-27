#include "Dog.hpp"

using std::cout;
using std::endl;
using std::string;

void	Dog::makeSound(void) const
{
	cout << "[Dog] Woof" << endl;
}

Dog::Dog()
{
	cout << "[Dog] Default constructor called" << endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &Dog) : Animal()
{
	cout << "[Dog] Copy constructor called" << endl;
	*this = Dog;
}

Dog &Dog::operator = (const Dog &Dog)
{
	cout << "[Dog] Copy assignment operator called" << endl;
	if (this == &Dog)
		return (*this);
	this->type = Dog.type;
	return (*this);
}

Dog::~Dog()
{
	cout << "[Dog] Destructor called" << endl;
}
