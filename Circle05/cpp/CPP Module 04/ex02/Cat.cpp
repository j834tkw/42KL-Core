#include "Cat.hpp"

using std::cout;
using std::endl;
using std::string;

void	Cat::makeSound(void) const
{
	cout << "[Cat] Meow" << endl;
}

Brain *Cat::getBrain()
{
	return (brain);
}

Cat::Cat()
{
	cout << "[Cat] Default constructor called" << endl;
	brain = new Brain;
	this->type = "Cat";
}

Cat::Cat(const Cat &Cat) : Animal()
{
	cout << "[Cat] Copy constructor called" << endl;
	*this = Cat;
}

Cat &Cat::operator = (const Cat &Cat)
{
	cout << "[Cat] Copy assignment operator called" << endl;
	if (this == &Cat)
		return (*this);
	this->type = Cat.type;
	this->brain = new Brain();
	*(this->brain) = *(Cat.brain);
	return (*this);
}

Cat::~Cat()
{
	cout << "[Cat] Destructor called" << endl;
	delete brain;
}
