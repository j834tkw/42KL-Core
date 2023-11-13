#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon		&weapon;

	public:
		void		attack(void);
	
		HumanA(std::string name, Weapon &weaponType);
		~HumanA(void);
};

#endif