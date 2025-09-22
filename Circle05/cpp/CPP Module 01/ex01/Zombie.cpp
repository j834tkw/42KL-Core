#include "Zombie.hpp"

using std::cout;
using std::endl;

void	Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie()
{
	cout << name << " suddenly explodes :skull:" << endl;
}