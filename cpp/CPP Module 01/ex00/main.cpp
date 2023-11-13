#include "Zombie.hpp"

int main()
{
	Zombie *zomzom = newZombie("Huehue");
	zomzom->announce();

	randomChump("Aeugh");

	delete zomzom;
	return (0);
}