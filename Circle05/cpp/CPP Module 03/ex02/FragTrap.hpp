#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap		&operator=(const FragTrap &obj);
		void			highFivesGuys(void);

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap(void);
};

#endif