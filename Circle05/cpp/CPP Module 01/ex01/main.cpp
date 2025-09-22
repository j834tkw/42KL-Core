#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie* 	zomzoms;
	int			headcount = 0;

	if (ac != 3)
	{
		zomzoms = zombieHorde(7, "Hngh");
		for (int i = 0; i < 7; i++)
			zomzoms[i].announce();
	}
	else
	{
		headcount = atoi(av[1]);
		std::string	zomzomsname = av[2];
		zomzoms = zombieHorde(headcount, zomzomsname);
		for (int i = 0; i < headcount; i++)
			zomzoms[i].announce();
	}

	delete[] zomzoms;
	return (0);
}

// In C++, the single object of the class which is created at runtime using a new operator is deleted by 
// using the delete operator, while the array of objects is deleted using the delete[] operator