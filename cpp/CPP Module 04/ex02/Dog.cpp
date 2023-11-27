#include "Dog.hpp"

using std::cout;
using std::endl;
using std::string;

void	Dog::makeSound(void) const
{
	cout << "[Dog] Woof" << endl;
}

Brain *Dog::getBrain(void)
{
	return (brain);
}

Dog::Dog()
{
	cout << "[Dog] Default constructor called" << endl;
	brain = new Brain;
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
	this->brain = new Brain();
	*(this->brain) = *(Dog.brain);
	return (*this);
}

Dog::~Dog()
{
	cout << "[Dog] Destructor called" << endl;
	delete brain;
}
