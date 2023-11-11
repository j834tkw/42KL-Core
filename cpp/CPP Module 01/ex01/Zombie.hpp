#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		void	announce(void);
		void	setName(std::string);
		Zombie(void);
		~Zombie(void);

};

Zombie* zombieHorde( int N, std::string name );

#endif