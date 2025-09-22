#include "Zombie.hpp"

int main()
{
	Zombie *zomzom = newZombie("Huehue");
	zomzom->announce();

	randomChump("Aeugh");

	delete zomzom;
	return (0);
}

// To allocate heap memory in C++, use the keyword new followed by the constructor of what you want to allocate.