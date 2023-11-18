#include "WrongCat.hpp"

using std::cout;
using std::endl;
using std::string;

void	WrongCat::makeSound(void) const
{
	cout << "[WrongCat] Meo.. sike. Uuwallalahyakllalahyokllalahyuk kgh kgh kghh.." << endl;
}

WrongCat::WrongCat()
{
	cout << "[WrongCat] Default constructor called" << endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal()
{
	cout << "[WrongCat] Copy constructor called" << endl;
	*this = WrongCat;
}

WrongCat &WrongCat::operator = (const WrongCat &WrongCat)
{
	if (this == &WrongCat)
		return (*this);
	this->type = WrongCat.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << "[WrongCat] Destructor called" << endl;
}
