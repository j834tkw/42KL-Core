#include "Zombie.hpp"

using std::cout;
using std::endl;

void	Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	cout << name << " suddenly explodes :skull:" << endl;
}
