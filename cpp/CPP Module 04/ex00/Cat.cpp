#include "Cat.hpp"

using std::cout;
using std::endl;
using std::string;

void	Cat::makeSound(void) const
{
	cout << "[Cat] Meow" << endl;
}

Cat::Cat()
{
	cout << "[Cat] Default constructor called" << endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &Cat) : Animal()
{
	cout << "[Cat] Copy constructor called" << endl;
	*this = Cat;
}

Cat &Cat::operator = (const Cat &Cat)
{
	if (this == &Cat)
		return (*this);
	this->type = Cat.type;
	return (*this);
}

Cat::~Cat()
{
	cout << "[Cat] Destructor called" << endl;
}
