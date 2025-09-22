#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		void			attack(const std::string& target);
		ScavTrap		&operator=(const ScavTrap &obj);
		void			guardGate(void);

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);
};

#endif